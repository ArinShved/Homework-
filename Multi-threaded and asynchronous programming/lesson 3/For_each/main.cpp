#include <iostream>
#include <vector>
#include <thread>
#include <future>

template<typename Iterator, typename Func>
void parl_for_each(Iterator start, Iterator end, Func f) {

	auto lenght = end - start;

	if (lenght <= 1) {
		if (start != end) {
			f(*start);
		}
		return;
	}
	
	Iterator mid = start + ((lenght) / 2);

	auto left_side = std::async(std::launch::async, parl_for_each<Iterator, Func>, start, mid, f);
	
	auto right_side = std::async(std::launch::async, parl_for_each<Iterator, Func>, mid, end, f);		

	left_side.get();
	right_side.get();
}

void sum(int& a) {
	 a += 2;
}


int main() {
	try {
		std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

		std::cout << "Arr: \t\t";
		for (const auto& i : arr) {
			std::cout << i << " "; 
		}

		std::cout << "\nArr * 3 : \t";

		parl_for_each(arr.begin(), arr.end(), [](int& v) {
			v *= 3;
			});

		for (const auto& i : arr) {
			std::cout << i << " "; 
		}

		std::cout << "\nNew_Arr + 2 : \t";

		parl_for_each(arr.begin(), arr.end(), sum);

		for (const auto& i : arr) {
			std::cout << i << " ";
		}

		std::cout << std::endl;

	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
