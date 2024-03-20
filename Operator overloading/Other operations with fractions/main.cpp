#include <iostream>

#include "class.h"
#include "functions.h"


int main(){
	setlocale(LC_ALL, "rus");

	int a, b, a_2, b_2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> b;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> a_2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> b_2;

	Fraction f1(a, b);
	Fraction f2(a_2, b_2);
	Fraction sum = f1 + f2;
	printResult(&f1, &f2, &sum, '+');
	Fraction difference = f1 - f2;
	printResult(&f1, &f2, &difference, '-');
	Fraction mul = f1 * f2;
	printResult(&f1, &f2, &mul, '*');
	Fraction div = f1 / f2;
	printResult(&f1, &f2, &div, '/');

	Fraction temp = f1;

	Fraction inc = ++f1 * f2;
	std::cout << "++";
	printResult(&temp, &f2, &inc, '*');

	std::cout << "Значение дроби 1 =  ";
	f1.print();
    std::cout << "\n";

	f1 = temp;

	Fraction inc_1 = f1++ * f2;
	printResultFI(&temp, &f2, &inc_1, '*', '+');
	std::cout << "Значение дроби 1 =  ";
	f1.print();
	std::cout << "\n";

	f1 = temp;

	Fraction dec = --f1 * f2;
	std::cout << "--";
	printResult(&temp, &f2, &dec, '*');
	std::cout << "Значение дроби 1 = ";
	f1.print();
	std::cout << "\n";

	f1 = temp;

	Fraction dec_1 = f1-- * f2;
	printResultFI(&temp, &f2, &dec_1, '*', '-');
	std::cout << "Значение дроби 1 =  ";
	f1.print();
	std::cout << "\n";
	f1 = temp;
	

	return 0;
}