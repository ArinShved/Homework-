#include<iostream>
#include <set>
#include <vector>


int main() {
	int size, num;
	std::set<int> set;
	setlocale(LC_ALL, "rus");

	std::cout << "[IN]:\n¬ведите размер: ";
	std::cin >> size;
	std::cout << "¬ведите числа:\n";
	for (int i = 0; i < size; i++) {
		std::cin >> num;
		set.insert(num);
	}

	std::vector<int> arr(set.begin(), set.end());
	std::reverse(arr.begin(), arr.end());
	
	std::cout << "[OUT]: \n";
	for (const auto& i : arr) {
		std::cout << i << "\n";
	}

	return 0;
}