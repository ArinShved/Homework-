
#include "figure.h"

	Figure::Figure() {
		name = "������ ";
		numOfSides = 0;
	}
	std::string const Figure::getName() {
		return name;
	}
	 void Figure::print() {
		std::cout << name << "\n " << "���������� ������: " << numOfSides << "\n";
	}
