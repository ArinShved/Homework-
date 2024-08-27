#include "function.h"

int one_vec_sum(std::vector<int> arr_1) {
	int sum = 0;
	for (int i = 0; i < arr_1.size(); i++) {
		sum += arr_1[i];
	}
	return sum;
}

std::vector<int> thread_sum_of_vec(std::vector<int> arr_1, std::vector<int> arr_2, int num_of_threads) {
	std::vector<int> result(arr_1.size());
	std::vector<std::thread> arr_thread(num_of_threads);
	int size = arr_1.size() / num_of_threads;

	for (int i = 0; i < num_of_threads; i++) {
		long start = i * num_of_threads;
		long end;
		i == num_of_threads - 1 ? end = arr_1.size() : end = (i + 1) * num_of_threads;
		arr_thread[i] = std::thread([&, start, end]() {
			for (int j = start; j < end; j++) {
				result[j] = arr_1[j] + arr_2[j];
			}
			});
	}

	for (auto& th : arr_thread) {
		th.join();
	}

	return result;
}
