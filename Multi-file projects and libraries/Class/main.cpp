#include <iostream>
#include <windows.h>

#include "header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::string answer;
	char a;
	int count;

	Counter c; 
	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> answer;
	if (answer == "да"|| answer == "Да"|| answer == "ДА") {
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> count;
		c = Counter(count); 
	}

	do {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> a;
		choosingCommand(c, a);
	} while (a != 'х');


	return 0;
}