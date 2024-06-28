#include <iostream>
#include <vector>

template<class T>
T squaring(T a) {
	return a * a;
}

template <>
std::vector<int> squaring(std::vector<int> arr) {
	std::vector<int> temp(arr.size());
	for (int i = 0; i < arr.size(); i++) {
		temp[i] = arr[i] * arr[i];
	}
	return temp;
}

void print_arr(std::vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

int main() {

	int a = 5;
	std::cout << "[In] = " << a << "\n[Out] = " << squaring(a);

	std::vector<int> arr = { -1, 4, 8 };
	std::cout << "\n[In] = ";
	print_arr(arr);
	std::cout << "[Out] = ";
	print_arr(squaring(arr));

	return 0;
}