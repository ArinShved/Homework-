#include "triangle.h"


    Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
		name = "Треугольник";
		numOfSides = 3;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}

	void Triangle::print()  {
		std::cout << name << "\n" <<
			"Стороны: a = " << a << ", b = " << b << ", c = " << c << "\n"
			<< "Углы: A = " << A << ", B = " << B << ", C = " << C << "\n" << "\n";
	}
	int const Triangle::geta() {
		return a;
	}
	int const Triangle::getb() {
		return b;
	}
	int const Triangle::getc() {
		return c;
	}
	int const Triangle::getA() {
		return A;
	}
	int const Triangle::getB() {
		return B;
	}
	int const Triangle::getC() {
		return C;
	}

