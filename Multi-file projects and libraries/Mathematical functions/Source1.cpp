#include <iostream>
#include "function.h"


int main() {
	setlocale(LC_ALL, "rus");
	int a, b, n;
	while (true) {
		std::cout << "������� ������ �����:  ";
		std::cin >> a;
		std::cout << "������� ������ �����:  ";
		std::cin >> b;
		std::cout << "�������� �������� (1 - ��������, 2 - ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������):  ";
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
			std::cout << "������! ������������ �����! " << "\n";
			break;
		}
		}

		std::cout << a << "\n";

	}

	return 0;
}