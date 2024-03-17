#include <iostream>
#include <string>

class Figure {
public:
	Figure() {
		name = "Фигура ";
		numOfSides = 0;
	}
	std::string const getName() {
		return name;
	}
	virtual void print() {
		std::cout << name << "\n " << "Количество сторон: " << numOfSides << "\n";
	}
protected:
	int numOfSides;
	std::string name;

};
class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C) {
		name = "Треугольник";
		numOfSides = 3;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}

	void print() override {
		std::cout << name << "\n" <<
			"Стороны: a = " << a << ", b = " << b << ", c = " << c << "\n"
			<< "Углы: A = " << A << ", B = " << B << ", C = " << C << "\n" << "\n";
	}
	int const geta() {
		return a;
	}
	int const getb() {
		return b;
	}
	int const getc() {
		return c;
	}
	int const getA() {
		return A;
	}
	int const getB() {
		return B;
	}
	int const getC() {
		return C;
	}
	
protected:
	int a, b, c;//length
	int A, B, C;//angle
};

class IsoscelesTriangle: public Triangle{
public:
	IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
		name = "Рaвнобедренный треугольник";
	}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a, int A) : Triangle(a, a, a, A, A, A) {
		name = "Рaвносторонний треугольник";
	}
};

class RightTriangle : public Triangle {	
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90){
		name = "Прямоугольный треугольник";
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		name = "Четырехугольник";
		numOfSides = 4;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	void print() override {
		std::cout << name << "\n" <<
			"Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << "\n"
			<< "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << "\n" << "\n";
	}
	int const geta() {
		return a;
	}
	int const getb() {
		return b;
	}
	int const getc() {
		return c;
	}
	int const getd() {
		return d;
	}
	int const getA() {
		return A;
	}
	int const getB() {
		return B;
	}
	int const getC() {
		return C;
	}
	int const getD() {
		return D;
	}

protected:
	int a, b, c, d;//length
	int A, B, C, D;//angle
};

class Rectangle : public Quadrangle {
public:
	Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
		name = "Прямоугольник";
	}
};

class Square : public Rectangle {
public:
	Square(int a) : Rectangle(a, a) {
		name = "Квадрат";
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B){
		name = "Параллелограм";
	}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B){
		name = "Ромб";
	}
};

void printInfo(Figure* figure) {
	figure->print();
}

int main() {
	setlocale(LC_ALL, "rus");
	
	Triangle triangle(10,20,30,40,50,60);
	printInfo(&triangle);

	IsoscelesTriangle isoTriangle(10, 20, 30, 40);
	printInfo(&isoTriangle);

	EquilateralTriangle equilTriangle(10, 20);
	printInfo(&equilTriangle);

	RightTriangle rTriangle(10,20,30,40,50);
	printInfo(&rTriangle);

	
	Quadrangle quadrangle(10,20,30,40,50,60,70,80);
	printInfo(&quadrangle);

	Rectangle rectangle(10,20);
	printInfo(&rectangle);

	Square square(10);
	printInfo(&square);

	Parallelogram parallelogram(10,20,30,40);
	printInfo(&parallelogram);

	Rhombus rhombus(10,20,30);
	printInfo(&rhombus);


	return 0;
}