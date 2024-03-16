#include <iostream>
#include <string>


class Figures {
public:
	Figures() {
		numOfSides = 0;
		name = "Фигура";
	}
	void const printResult() {
		std::cout << name << ": " <<  numOfSides << "\n";
	}
protected:	
	std::string name;
	int numOfSides;	
};

class Triangle : public Figures {
public:
	Triangle() {
		numOfSides = 3;
		name = "Треугольник";
	}
};

class Quadrangle : public Figures {
public:
	Quadrangle() {
		numOfSides = 4;
		name = "Четырехугольник";
	}
};


int main() {
	setlocale(LC_ALL, "rus");

	Figures figures;
	Triangle triangle;
	Quadrangle quadrangle;

	std::cout << "Количество сторон:  " << "\n";
	figures.printResult();
	triangle.printResult();
	quadrangle.printResult();

	return 0;
}