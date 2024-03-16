#include <iostream>
#include <string>

class Figure {
public:
	Figure() {
		name = "Фигура";
		numOfSides = 0;
		right = check();
	}
	 virtual void printInfo() {
		if (check()) {
			std::cout << name << "\n" << "Правильная" << "\n" << "Количество сторон: " << numOfSides << "\n" << "\n";
		}
		else {
			std::cout << name << "\n" << "Неправильная" << "\n" << "Количество сторон: " << numOfSides << "\n" << "\n";
		}
	}
	virtual bool check() {
		return numOfSides == 0;
	}
protected:
	bool right;
	std::string name;
	int numOfSides;

};


class Triangle : public Figure{
public:
	Triangle(int numOfSides, int a, int b, int c, int A, int B, int C) {
		name = "Треугольник";
		this->numOfSides = numOfSides;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		right = check();
	}
	 void printInfo() override{
		std::cout << name << "\n";
		if (check()) {
			std::cout << "Правильная" << "\n";
		}
		else {
			std::cout << "Неправильная" << "\n";
		}
		std::cout << "Количество сторон: " << numOfSides << "\n";
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << "\n";
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << "\n" << "\n";
	}
	bool check() override {
		if (numOfSides == 3 && (A + B + C == 180))
			return true;
		else {
			return 0;
		}
	}
protected:
	int a, b, c;//length
	int A, B, C;//angle
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int numOfSides, int a, int b, int c, int A, int B, int C) : Triangle(numOfSides, a, b, c, A, B, C) {
		name = "Рaвнобедренный треугольник";
	}
	bool check() override {
		return numOfSides == 3 && a == c && A == C && A + C + B == 180;
	}

};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int numOfSides, int a, int b, int c, int A, int B, int C) : Triangle(numOfSides, a, b, c, A, B, C) {
		name = "Рaвносторонний треугольник";
	}
	bool check() override {
		return numOfSides == 3 && a == c && A == C && c == b && C == B && A + C + B == 180;
	}
};

class RightTriangle : public Triangle {
public:
	RightTriangle(int numOfSides, int a, int b, int c, int A, int B, int C) : Triangle(numOfSides, a, b, c, A, B, C) {
		name = "Прямоугольный треугольник";
	}
	bool check() override {
		return numOfSides == 3 && C == 90 && C + B + A == 180;
	}
};

class Quadrangle : public Figure{
public:
	Quadrangle(int numOfSides, int a, int b, int c, int d, int A, int B, int C, int D) {
		name = "Четырехугольник";
		this->numOfSides = numOfSides;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		right = check();
	}
	void printInfo() override {
		std::cout << name << "\n";
		if (check()) {
			std::cout << "Правильная" << "\n";
		}
		else {
			std::cout << "Неправильная" << "\n";
		}
		std::cout << "Количество сторон: " << numOfSides << "\n";
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d <<  "\n";
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << "\n" << "\n";
	}
	bool check() override {
		return numOfSides == 4 && A + B + C + D == 360;
	}
protected:
	std::string name;
	int a, b, c, d;//length
	int A, B, C, D;//angle
};

class Rectangle : public Quadrangle {
public:
	Rectangle(int numOfSides, int a, int b) : Quadrangle(numOfSides, a, b, a, b, 90, 90, 90, 90) {
		name = "Прямоугольник";
	}
	bool check() override {
		return numOfSides == 4 && a == c && b == d && A == 90 && A == C && C == D && D == B && A + B + C + D == 360;
	}
};

class Square : public Rectangle {
public:
	Square(int numOfSides,  int a) : Rectangle(numOfSides, a, a) {
		name = "Квадрат";
	}

	bool check() override {
		return numOfSides == 4 && a == b && b == c && c == d && A == 90 && A == C && C == D && D == B;
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int numOfSides, int a, int b, int A, int B) : Quadrangle(numOfSides, a, b, a, b, A, B, A, B) {
		name = "Параллелограм";
	}
	bool check() override {
		return numOfSides == 4 && a == c && b == d && A == C && D == B && A + B + C + D == 360;
	}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int numOfSides, int a, int A, int B) : Parallelogram(numOfSides, a, a, A, B) {
		name = "Ромб";
	}
	bool check() override {
		return numOfSides == 4 && a == b && b == c && c == d && A == C && D == B && A + B + C + D == 360;
	}
};


int main() {
	setlocale(LC_ALL, "rus");

	Figure figure;
	figure.printInfo();

	Figure* figureT;
	Triangle triangle1(4, 10, 20, 30, 40, 50, 60);
	figureT = &triangle1;
	figureT->printInfo();

	IsoscelesTriangle isoTriangle(3, 10, 20, 10, 30, 120, 30);
	Figure* tri = &isoTriangle;
	tri->printInfo();

	Figure* equ =  new EquilateralTriangle(3, 10, 20, 30, 40, 50, 60);
	equ->printInfo();

	Figure* rTri = new RightTriangle(3, 10, 20, 30, 40, 50, 90);
	rTri->printInfo();

	Figure* qua = new Quadrangle(4, 10, 20, 30, 40, 50, 60, 70, 80);
	qua->printInfo();

	Rectangle rectangle(5, 10, 20);
	Figure* figureQ = &rectangle;
	figureQ->printInfo();

	Square square(4, 10);
    figureQ = &square;
	figureQ->printInfo();

	Parallelogram parallelogram(4, 10, 20, 30, 40);
	figureQ = &parallelogram;
	figureQ->printInfo();

	Rhombus rhombus(3, 10, 20, 30);
	figureQ = &rhombus;
	figureQ->printInfo();

	delete qua;
	delete equ;
	delete rTri;

	return 0;
}