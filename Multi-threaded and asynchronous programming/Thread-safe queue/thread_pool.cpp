#include "thread_pool.h"

ThreadPool::ThreadPool() {
    done = false;
    int threads_num = std::thread::hardware_concurrency();
    for (size_t i = 0; i < threads_num; ++i) {
        threads.emplace_back([this] {
            this->work(); 
            });
    }
};

void ThreadPool::work() {
    while (!done) {
        try {
            std::function<void()> task = std::move(tasks.queue_pop());
            task();
        }
        catch (const std::runtime_error& e) {
            break;
        }
    }
};

ThreadPool::~ThreadPool() {
    done = true;
    tasks.set_done();
    
    for (std::thread& i : threads) {
        if (i.joinable()) {
            i.join();
        }
    }
};
    
void ThreadPool::submit(std::function<void()> func) {
    tasks.queue_push(func);
};
  