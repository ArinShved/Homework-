#include <iostream>

void quick_sort(int* arr, int size) {
	int i = 0;
	int j = size - 1;

	int pivot = arr[size / 2];

	do {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			i++;
			j--;
		}

	} while (i <= j);

	if (j > 0) {
		quick_sort(arr, j + 1);
	}
	if (i < size) {
		quick_sort(&arr[i], size - i);
	}
}


int main() {
	setlocale(LC_ALL, "rus");
	int arr[10] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };

	std::cout << "Исходный массив: ";
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	quick_sort(arr, 10);
	std::cout << "\nОтсортированный массив: ";
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}

	int arr_1[15] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	std::cout << "\n\nИсходный массив: ";
	for (int i = 0; i < 15; i++) {
		std::cout << arr_1[i] << " ";
	}
	quick_sort(arr_1, 15);
	std::cout << "\nОтсортированный массив: ";
	for (int i = 0; i < 15; i++) {
		std::cout << arr_1[i] << " ";
	}
	
	int arr_2[18] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	std::cout << "\n\nИсходный массив: ";
	for (int i = 0; i < 18; i++) {
		std::cout << arr_2[i] << " ";
	}
	quick_sort(arr_2, 18);
	std::cout << "\nОтсортированный массив: ";
	for (int i = 0; i < 18; i++) {
		std::cout << arr_2[i] << " ";
	}


	return 0;
}