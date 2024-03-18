
#include "figure.h"

	Figure::Figure() {
		name = "Фигура  ";
		numOfSides = 0;
	}
	std::string const Figure::getName() {
		return name;
	}
	 void Figure::print() {
		std::cout << name << "\n " << "Количество сторон: " << numOfSides << "\n";
	}
