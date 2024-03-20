#pragma once

class Fraction
{
private:
	int numerator_;
	int denominator_;
public:
	Fraction(int numerator, int denominator);
	void print();
	double sub();
	void reduction(int& num, int& den);
	bool operator ==(Fraction other);
	bool operator !=(Fraction other);
	bool operator >(Fraction other);
	bool operator <(Fraction other);
	bool operator >=(Fraction other);
	bool operator <=(Fraction other);
	Fraction operator -(Fraction other);
	Fraction operator +(Fraction other);
	Fraction operator *(Fraction other);
	Fraction operator /(Fraction other);
	Fraction& operator ++();
	Fraction operator ++(int);
	Fraction& operator --();
	Fraction operator --(int);
};