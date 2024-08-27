#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "function.h"

int main() {
	setlocale(LC_ALL, "rus");
	std::vector<int> arr_1(1000);
    std::vector<int> arr_2(10000);
	std::vector<int> arr_3(100000);
	std::vector<int> arr_4(1000000);

	std::vector<std::vector<int>> arr = { arr_1, arr_2, arr_3, arr_4 };

	int cores_count = std::thread::hardware_concurrency();

	std::cout << "ƒоступное количество €дер: " << cores_count << "\n";
	std::cout << "\t\t " << 1000 << "\t\t\t " << 10000 << "\t\t\t " << 100000 << "\t\t\t " << 1000000 << "\n";

	std::cout << "1 поток :  ";
	for (int i = 0; i < 4; i++) {
		auto start = std::chrono::steady_clock::now();
		std::vector<int> res = thread_sum_of_vec(arr[i], arr[i], 1);
		int sum = one_vec_sum(res);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "\t " << std::fixed << time.count() <<  "\t ";
	}

	for (int thread_num = 2; thread_num <= 16; thread_num *= 2) {
		thread_num < 8 ? (std::cout << "\n" << thread_num << " потока :") : (std::cout << "\n" << thread_num << " потоков :");
		for (int i = 0; i < 4; i++) {
			auto start = std::chrono::steady_clock::now();
			std::vector<int> res = thread_sum_of_vec(arr[i], arr[i], thread_num);
			int sum = one_vec_sum(res);
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> time = end - start;
			std::cout << "\t " << time.count() << "\t ";
		}
	}

	return 0;
}