#include "camel_speedboad.h"

CamelSpB::CamelSpB() : Camel() {
	this->name = "Верблюд-быстроход";
	this->speed = 40;
	this->rest = 5;
	this->time_b_rest = 10;
}

double CamelSpB::changeOfTime(int i) {
	if (i == 1) {
		return 5;
	}
	else if (i == 2) {
		return 5 + 6.5;
	}
	else {
		return 5 + 6.5 + (8 * (i - 2));
	}
}
