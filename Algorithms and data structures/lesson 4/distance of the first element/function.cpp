
#include "function.h"

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	std::cout << "Динамический массив: ";
	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size) {
			std::cout << arr[i] << " ";
		}
		else {
			std::cout << " _ ";
		}
	}

	std::cout << "\n";
};

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {
	logical_size--;
	if (logical_size > (actual_size / 3)) {
		for (int i = 0; i < logical_size; i++) {
			arr[i] = arr[i + 1];
		}
		return arr;
	}
	else {
		if (actual_size / 3 > 0) {
			int* new_arr = new int[actual_size / 3];
			for (int i = 0; i < actual_size/3; i++) {
				new_arr[i] = arr[i + 1];
			}
			actual_size /= 3;
			delete[]arr;
			return new_arr;
		}
		else {
			return {};
		}
	}
};
