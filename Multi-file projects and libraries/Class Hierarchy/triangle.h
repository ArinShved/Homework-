#pragma once
#include "figure.h"

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	void print() override;
	int const geta();
	int const getb();
	int const getc();
	int const getA();
	int const getB();
	int const getC();
protected:
	int a, b, c;//length
	int A, B, C;//angle
};
