#include "thread_pool.h"

ThreadPool::ThreadPool() {
    int threads_num = std::thread::hardware_concurrency();
    for (size_t i = 0; i < threads_num; ++i) {
        threads.emplace_back([this] {
            this->work(); 
            });
    }
};

void ThreadPool::work() {
    while (true) {
        std::function<void()> task; {
            std::unique_lock<std::mutex> lock(thread_mutex);
            notification.wait(lock, [this] { return !tasks.queue_empty() || done;
                });
            if (done && tasks.queue_empty())
                return;
            task = std::move(tasks.queue_pop());
        }
        task();
    }
};

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(thread_mutex);
        done = true;
    }
    notification.notify_all();
    for (std::thread& i : threads) {
        i.join();
    }
};
    
void ThreadPool::submit(std::function<void()> func) {
    {
        std::lock_guard<std::mutex> lock(thread_mutex);
        tasks.queue_push(func);
    }
    notification.notify_one();
};
  