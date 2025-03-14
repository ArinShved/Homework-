#include "safe_queue.h"
/*
template <typename T>
T SafeQueue<T>::queue_pop() {
	std::unique_lock<std::mutex> lock(mtx);
	notification.wait(lock, [this] {
		return !p_queue.empty();
		});
	T data = p_queue.front();
	p_queue.pop();
	return data;
}

template <typename T>
void SafeQueue<T>::queue_push(T task) {
	std::unique_lock<std::mutex> lock(mtx);
	p_queue.push(task);	
	notification.notify_one();
}
template <typename T>
bool SafeQueue<T>::queue_empty() {
	return p_queue.empty();
}
*/

