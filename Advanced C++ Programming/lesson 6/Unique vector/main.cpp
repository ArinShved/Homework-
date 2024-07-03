#include <iostream>
#include <vector>
#include <algorithm>


void sort_arr(std::vector<int>& arr) {
	std::sort(arr.begin(), arr.end());
	auto it = std::unique(arr.begin(), arr.end());
	arr.erase(it, arr.end());
}

int main() {
	std::vector<int> arr = { 1, 1, 2, 5, 6, 1, 2, 4 };
	std::cout << "[IN]:";
	for (const auto& i : arr) {
		std::cout << i << " ";
	}

	sort_arr(arr);

	std::cout << "\n[OUT]: ";
	for (const auto& i : arr) {
		std::cout << i << " ";
	}

	return 0;
}