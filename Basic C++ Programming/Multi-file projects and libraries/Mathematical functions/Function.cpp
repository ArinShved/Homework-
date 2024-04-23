#include "function.h"

int sum(int a, int b) {
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int multiplication(int a, int b) {
	return a * b;
}

int division(int a, int b) {
	return a / b;
}

int exponentiation(int a, int b) {
	int temp = a;
	for (int i = 1; i < b; i++) {
		a *= temp;
	}
	return a;
}
