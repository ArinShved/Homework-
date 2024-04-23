#pragma once

#include "figure.h"

class Quadrangle : public Figure {
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
	void print() override;
	int const geta();
	int const getb();
	int const getc();
	int const getd();
	int const getA();
	int const getB();
	int const getC();
	int const getD();

protected:
	int a, b, c, d;//length
	int A, B, C, D;//angle
};

