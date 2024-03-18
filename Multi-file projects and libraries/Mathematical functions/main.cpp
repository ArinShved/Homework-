#include <iostream>
#include "function.h"


int main() {
	setlocale(LC_ALL, "rus");
	int a, b, n;
	while (true) {
		std::cout << "Введите первое число: ";
		std::cin >> a;
		std::cout << "Введите второе число:  ";
		std::cin >> b;
		std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
		std::cin >> n;

		switch (n) {
		case 1:
		{
			a = sum(a, b);
			break;
		}
		case 2:
		{
			a = sub(a, b);
			break;
		}
		case 3:
		{
			a = multiplication(a, b);
			break;
		}
		case 4:
		{
			a = division(a, b);
			break;
		}
		case 5:
		{
			a = exponentiation(a, b);
			break;
		}
		default:
		{
			std::cout << "Ошибка! Неправильное число! " << "\n";
			break;
		}
		}

		std::cout << a << "\n";

	}

	return 0;
}
