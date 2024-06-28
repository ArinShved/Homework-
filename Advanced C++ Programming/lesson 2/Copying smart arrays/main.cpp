#include <iostream>

class smart_array {
private:
	int* array;
	int size;
	int length;
public:
	smart_array(int new_size) {
		array = new int[new_size];
		size = new_size;
		length = 0;
	}
	smart_array(const smart_array& arr) {
		size = arr.size;
		length = arr.length;
		array = new int[size];
		std::copy(arr.array, arr.array + length, array);
	}
	void add_element(int num) {
		if (length >= size) {
			int* temp = new int[size * 2];
			std::copy(array, array + size, temp);
			delete[] array;
			array = temp;
			delete[] temp;
			size *= 2;
		}
		array[length] = num;
		length++;
	}
	int get_element(int i) {
		if (i >= length) {
			throw std::out_of_range("Индекс за пределами размера");
		}

		return array[i];
	}
	int get_length() {
		return length;
	}

	smart_array& operator=(const smart_array& arr) {
		if (this != &arr) {
			delete[] array;
			size = arr.size;
			length = arr.length;
			array = new int[size];
			std::copy(arr.array, arr.array + length, array);
		}
		return *this;
	}
	~smart_array() {
		delete[] array;
	}
};



int main() {
	setlocale(LC_ALL, "rus");

	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	std::cout << "Первоначальный массив: ";
	for (int i = 0; i < arr.get_length(); i++) {
		std::cout << arr.get_element(i) << " ";
	}
	std::cout << "\n";


	std::cout << "Скопированный массив с помощью конструктора копирования: ";
	smart_array copy(arr);
	for (int i = 0; i < copy.get_length(); i++) {
		std::cout << copy.get_element(i) << " ";
	}
	std::cout << "\n";

	
	std::cout << "Скопированный массив с помощью перегруженного оператора: ";
	arr = new_array;
	for (int i = 0; i < arr.get_length(); i++) {
		std::cout << arr.get_element(i) << " ";
	}
	std::cout << "\n";


	return 0;
}