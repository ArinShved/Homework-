
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
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_i) {
	if (logical_size < actual_size) {
		arr[logical_size] = new_i;
		logical_size++;
		return arr;
	}
	else {
		int* new_arr = new int[actual_size * 2];
		for (int i = 0; i < actual_size; i++) {
			new_arr[i] = arr[i];
		}
		new_arr[logical_size] = new_i;
		delete []arr;
		logical_size++;
		actual_size *= 2;
		return new_arr;
	}
}