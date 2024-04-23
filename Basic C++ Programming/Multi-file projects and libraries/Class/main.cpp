#include <iostream>
#include <windows.h>

#include "class.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::string answer;
	char a;
	int count;

	Counter* c = nullptr; 
	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> answer;
	if (answer == "да") {
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> count;
		c = new Counter(count);
	}
	else
	{
		c = new Counter();
	}

	do {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> a;
		choosingCommand(*c, a);
	} while (a != 'х');

	delete c;

	return 0;
}