#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	double sub() {
		return numerator_ / denominator_;
	}
	bool operator ==(Fraction other) { 
		return numerator_ == other.numerator_ && denominator_ == other.denominator_;
	}
	bool operator !=(Fraction other) {
		return !(*this == other);
	}
	bool operator >(Fraction other) {
		int num = numerator_ * other.denominator_;
		int num_2 = other.numerator_ * denominator_;
		return num > num_2;
	}
	bool operator <(Fraction other) {
		int num = numerator_ * other.denominator_;
		int num_2 = other.numerator_ * denominator_;
		return num < num_2;
	}
	bool operator >=(Fraction other) {
		return !(*this < other);
	}
	bool operator <=(Fraction other) {
		return !(*this > other);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}