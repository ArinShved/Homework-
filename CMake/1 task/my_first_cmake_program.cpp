
#include "my_first_cmake_program.h"


int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	
	std::string st;
	std::cout << "Введите ваше имя:  " << "\n";
	std::getline(std::cin, st);
	std::cout << "Здравствуйте, " << st << "\n";

	system("pause");
	return 0;
}
