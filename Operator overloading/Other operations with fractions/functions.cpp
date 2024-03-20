#include <iostream>
#include "class.h"
#include "functions.h"

void printResult(Fraction* f1, Fraction* f2, Fraction* f3, char symbol) {
	f1->print();
	std::cout << " " << symbol << "  ";
	f2->print();
	std::cout << " = ";
	f3->print();
	std::cout << "\n";
}
void printResultFI(Fraction* f1, Fraction* f2, Fraction* f3, char symbol, char plusOrMinus) {
	f1->print();
	std::cout << plusOrMinus << plusOrMinus << " " << symbol << "  ";
	f2->print();
	std::cout << " = ";
	f3->print();
	std::cout << "\n";
}