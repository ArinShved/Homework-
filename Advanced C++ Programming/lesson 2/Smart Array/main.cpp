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
	void add_element(int num) {
		if (length >= size) {
			int* temp = new int[size * 2];
			std::copy(array, array + size, temp);
			delete[] array;
			array = temp;
			size*=2;
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
	~smart_array() {
		delete[] array;
	}

};


int main() {
	setlocale(LC_ALL, "rus");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		
		std::cout << arr.get_element(1) << std::endl;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}