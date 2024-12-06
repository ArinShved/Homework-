#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>

std::mutex mtx;

int min_index(std::vector<int>& numbers, int start) {
	int min_num = numbers[start];
	int index = numbers.size() - 1;
	std::lock_guard<std::mutex> lock(mtx);
	for (int i = start; i < numbers.size(); i++) {
		if (numbers[i] <= min_num) {
			min_num = numbers[i];
			index = i;
		}
	}
	return index;
}

void selection_sort(std::vector<int>& numbers) {

	for (int i = 0; i < numbers.size(); i++) {
		std::promise<int> promise;
		std::future<int> future = promise.get_future();

		std::thread( [&promise, &numbers, i]() {
			int min_i =  min_index(numbers, i);
			promise.set_value(min_i);
			}).detach();

		int future_i = future.get();

		std::swap(numbers[i], numbers[future_i]);
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	try {
		std::vector<int> num{ 5, 6, 4, 7, 10, 33, 6, 10, 5, 7, 4, 3, 1, 0, 0, 7, 88, 98, 134, 2, 1, 0, 22, 55 };
		std::cout << "Начальный список: ";
		for (const auto& i : num) {
			std::cout << i << " ";
		}

		selection_sort(num);

		std::cout << "\nОтсортированный список: ";
		for (const auto& i : num) {
			std::cout << i << " ";
		}
	}
	catch ( const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}