#include "quadrangle.h"

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
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
void Quadrangle::print(){
	std::cout << name << "\n" <<
		"Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << "\n"
		<< "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << "\n" << "\n";
}
int const Quadrangle::geta() {
	return a;
}
int const Quadrangle::getb() {
	return b;
}
int const Quadrangle::getc() {
	return c;
}
int const Quadrangle::getd() {
	return d;
}
int const Quadrangle::getA() {
	return A;
}
int const Quadrangle::getB() {
	return B;
}
int const Quadrangle::getC() {
	return C;
}
int const Quadrangle::getD() {
	return D;
}