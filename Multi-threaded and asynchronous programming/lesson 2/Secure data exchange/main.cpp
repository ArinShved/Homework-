#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>

#include "functions.h"
#include "class.h"


int main() { 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Data first(1);
	Data second(7);

	std::cout << "Начальные значения. \tПервый класс: " << first.get_number() << "  Второй класс: " << second.get_number() << "\n";

	std::cout << "Потоки. Swap_lock:";
	print_func(swap_lock, first, second);

	std::cout << "Swap_scopedlock:";
	print_func(swap_scopedlock, first, second);

	std::cout << "Swap_uniquelock:";
	print_func(swap_uniquelock, first, second);
	
	return 0;
}