#include <iostream>
#include <string>


class Triangle {
public:
	Triangle(int a, int b, int c, int A, int B, int C) {
		name = "Треугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;	
	}
	std::string const getName() {
		return name;
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
	std::string name;
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

class Quadrangle {
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		name = "Четырехугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	std::string const getName() {
		return name;
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
	std::string name;
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


void printInfoT(Triangle* triangle) {
	std::cout << triangle->getName() << "\n"
		"Стороны: a = " << triangle->geta() << ", b = " << triangle->getb() << ", c = " << triangle->getc() << "\n"
		<< "Углы: A = " << triangle->getA() << ", B = " << triangle->getB() << ", C = " << triangle->getC() << "\n" << "\n";
}
void printInfoQ(Quadrangle* quadrangle) {
	std::cout << quadrangle->getName() << "\n"
		"Стороны: a = " << quadrangle->geta() << ", b = " << quadrangle->getb() << ", c = " << quadrangle->getc() << ", d = " << quadrangle->getd() << "\n"
		<< "Углы: A = " << quadrangle->getA() << ", B = " << quadrangle->getB() << ", C = " << quadrangle->getC() << ", D = " << quadrangle->getD() << "\n" << "\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	
	Triangle triangle(10,20,30,40,50,60);
	printInfoT(&triangle);

	IsoscelesTriangle isoTriangle(10, 20, 30, 40);
	printInfoT(&isoTriangle);

	EquilateralTriangle equilTriangle(10, 20);
	printInfoT(&equilTriangle);

	RightTriangle rTriangle(10,20,30,40,50);
	printInfoT(&rTriangle);

	
	Quadrangle quadrangle(10,20,30,40,50,60,70,80);
	printInfoQ(&quadrangle);

	Rectangle rectangle(10,20);
	printInfoQ(&rectangle);

	Square square(10);
	printInfoQ(&square);

	Parallelogram parallelogram(10,20,30,40);
	printInfoQ(&parallelogram);

	Rhombus rhombus(10,20,30);
	printInfoQ(&rhombus);


	return 0;
}