#include "functions.h"


void swap(Data& first, Data& second) {
	int temp = first.get_number();
	first.set_value(second.get_number());
	second.set_value(temp);
}

void swap_lock(Data& first, Data& second) {
	std::lock(first.mtx, second.mtx);
	std::lock_guard<std::mutex> lockA(first.mtx, std::adopt_lock);
	std::lock_guard<std::mutex> lockB(second.mtx, std::adopt_lock);

	swap(first, second);
	
}

void swap_scopedlock(Data& first, Data& second) {
	std::scoped_lock lock(first.mtx, second.mtx);

	swap(first, second);
}

void swap_uniquelock(Data& first, Data& second) {
	std::unique_lock<std::mutex> lockA(first.mtx);
	std::unique_lock<std::mutex> lockB(second.mtx);

	swap(first, second);
}

void print_func(void(*func_name)(Data&, Data&), Data& first, Data& second) {
	std::thread th(func_name, std::ref(first), std::ref(second));
	std::thread th1(func_name, std::ref(first), std::ref(second));
	std::thread th2(func_name, std::ref(first), std::ref(second));
	th.join();
	th1.join();
	th2.join();
	std::cout << "\tПервый класс: " << first.get_number() << "  Второй класс: " << second.get_number() << "\n";
}
