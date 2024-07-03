#include <iostream>
#include <vector>

template<class T>
T squaring(T a) {
	return a * a;
}

template <class T>
std::vector<T> squaring(std::vector<T> arr) {
	std::vector<T> temp(arr.size());
	for (int i = 0; i < arr.size(); i++) {
		temp[i] = arr[i] * arr[i];
	}
	return temp;
}

template <class T>
void print_arr(std::vector<T> arr) {
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