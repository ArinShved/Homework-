
#include "figure.h"
#include "triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "right_triangle.h"
#include "quadrangle.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "rhombus.h"
#include "square.h"


void printInfo(Figure* figure) {
	figure->print();
} 

int main() {
	setlocale(LC_ALL, "rus");

	Triangle triangle(10, 20, 30, 40, 50, 60);
	printInfo(&triangle);

	IsoscelesTriangle isoTriangle(10, 20, 30, 40);
	printInfo(&isoTriangle);

	EquilateralTriangle equilTriangle(10, 20);
	printInfo(&equilTriangle);

	RightTriangle rTriangle(10, 20, 30, 40, 50);
	printInfo(&rTriangle);


	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	printInfo(&quadrangle);

	Rectangle rectangle(10, 20);
	printInfo(&rectangle);

	Square square(10);
	printInfo(&square);

	Parallelogram parallelogram(10, 20, 30, 40);
	printInfo(&parallelogram);

	Rhombus rhombus(10, 20, 30);
	printInfo(&rhombus);

	system("pause");
	return 0;
}