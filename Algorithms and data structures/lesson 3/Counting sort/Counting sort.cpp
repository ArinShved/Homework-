
#include <iostream>

void count_sort(int* arr, int const size) {
	int* count = new int[size];
	for (int i = 0; i < size; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		count[arr[i]] = count[arr[i]] + 1;
	}

	int num = 0;
	for (int i = 0; i < size; i++) {
		while (count[i] != 0) {
			arr[num] = i;
			count[i]--;
			num++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[30] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };

	std::cout << "Исходный массив: ";
	for (int i = 0; i < 30; i++) {
		std::cout << arr[i] << " ";
	}
	count_sort(arr, 30);
	std::cout << "\nОтсортированный массив: ";
	for (int i = 0; i < 30; i++) {
		std::cout << arr[i] << " ";
	}


	int arr_1[40] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };

	std::cout << "\n\nИсходный массив: ";
	for (int i = 0; i < 40; i++) {
		std::cout << arr_1[i] << " ";
	}
	count_sort(arr_1, 40);
	std::cout << "\nОтсортированный массив: ";
	for (int i = 0; i < 40; i++) {
		std::cout << arr_1[i] << " ";
	}


	return 0;
}

