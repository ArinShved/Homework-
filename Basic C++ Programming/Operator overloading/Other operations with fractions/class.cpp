#include <iostream>
#include "class.h"


Fraction::Fraction(int numerator, int denominator)	{
	numerator_ = numerator;
	denominator_ = denominator;
}


void Fraction::print() {
	if (numerator_ == 0) {
		std::cout << "0";
	}
	else {
		std::cout << numerator_ << "/" << denominator_ << " ";
	}
}

double Fraction::sub() {
	return numerator_ / denominator_;
}

void Fraction::reduction(int& num, int& den) {
	for (int i = 100; i > 1; i--) {
    	if (num % i == 0 && den % i == 0) {
			num /= i;
			den /= i;
			break;
		}
	}
}
bool Fraction::operator ==(Fraction other) {
	return sub() == other.sub();
}
bool Fraction::operator !=(Fraction other) {
	return !(*this == other);
}
bool Fraction::operator >(Fraction other) {
	return sub() > other.sub();
}
bool Fraction::operator <(Fraction other) {
	return sub() < other.sub();
}
bool Fraction::operator >=(Fraction other) {
	return !(*this < other);
}
bool Fraction::operator <=(Fraction other) {
	return !(*this > other);
}
Fraction Fraction::operator -(Fraction other) {
	int num = numerator_ * other.denominator_ - other.numerator_ * denominator_;
	int den = denominator_ * other.denominator_;
	reduction(num, den);
	return Fraction(num, den);
}
Fraction Fraction::operator +(Fraction other) {
	int num = numerator_ * other.denominator_ + other.numerator_ * denominator_;
	int den = denominator_ * other.denominator_;
	reduction(num, den);
	return Fraction(num, den);
}
Fraction Fraction::operator *(Fraction other) {
	int num = numerator_ * other.numerator_;
	int den = denominator_ * other.denominator_;
	reduction(num, den);
	return Fraction(num, den);
}
Fraction Fraction::operator /(Fraction other) {
	int num = numerator_ * other.denominator_;
	int den = denominator_ * other.numerator_;
	reduction(num, den);
	return Fraction(num, den);
}
Fraction& Fraction::operator ++() {
	numerator_ += denominator_;
	return *this;
}
Fraction Fraction::operator ++(int) {
	Fraction temp = *this;
	numerator_ += denominator_;
	return temp;
}
Fraction& Fraction::operator --() {
	numerator_ -= denominator_;
	return *this;
}
Fraction Fraction::operator --(int) {
	Fraction temp = *this;
	numerator_ -= denominator_;
	return temp;
}