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
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
	std::cin >> answer;
	if (answer == "��"|| answer == "��"|| answer == "��") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> count;
		c = Counter(count); 
	}

	do {
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> a;
		choosingCommand(c, a);
	} while (a != '�');


	return 0;
}