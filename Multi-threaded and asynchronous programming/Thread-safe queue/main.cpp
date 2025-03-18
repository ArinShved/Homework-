#include <iostream>
#include <chrono>

#include "thread_pool.h"

void func_1() {
	std::cout << "Func 1\n";
}

void func_2() {
	std::cout << "Func 2\n";
}

int main() {
	ThreadPool pool;

	for (int i = 0; i < 10; i++) {
		pool.submit(func_1);
		pool.submit(func_2);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}