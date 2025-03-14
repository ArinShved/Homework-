#pragma once
#include <vector>
#include <thread>
#include <functional>
#include <future>
#include <mutex>
#include <iostream>

#include "safe_queue.h"


class ThreadPool
{
public:
	ThreadPool();
	void submit(std::function<void()> func);
	void work();
	~ThreadPool();
private:
	std::vector<std::thread> threads;
	SafeQueue<std::function<void()>> tasks;
	std::mutex thread_mutex;
	std::condition_variable notification;
	bool done = false;
	
};

