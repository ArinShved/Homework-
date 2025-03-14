#pragma once
#include <queue>
#include <mutex>
#include <thread>

template<typename T>
class SafeQueue{
public:
	T queue_pop() {
		std::unique_lock<std::mutex> lock(mtx);
		notification.wait(lock, [this] {
			return !task_queue.empty();
			});
		T data = task_queue.front();
		task_queue.pop();
		return data;
	};

	void queue_push(T task) {
		std::unique_lock<std::mutex> lock(mtx);
		task_queue.push(task);
		notification.notify_one();
	};

	bool queue_empty() {
		return task_queue.empty();
	};
private:
	std::queue<T> task_queue;
	std::mutex mtx;
	std::condition_variable notification;
};

