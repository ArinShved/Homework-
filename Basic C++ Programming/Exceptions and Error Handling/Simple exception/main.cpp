#include <iostream>
#include <string>
#include <Windows.h>
#include "function_and_exception.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int forbiddenLength = 0;
	std::cout << "Введите запретную длину:  ";
	std::cin >> forbiddenLength;
	do {
		std::string str;
		std::cout << "Введите слово: ";
		std::cin >> str;
		try {
			int a = function(str, forbiddenLength);
			std::cout << "Длина слова ''" << str << "'' равна " << str.size() << "\n";
		}
		catch (const BadLength& ex) {
			std::cout << ex.what() << "\n";
			break;
		}
	} while (true);

	return 0;
}