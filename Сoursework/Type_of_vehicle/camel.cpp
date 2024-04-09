#include "camel.h"

Camel::Camel() :GroundV() {
	this->name = "Верблюд";
	this->speed = 10;
	this->rest = 5;
	this->time_b_rest = 30;
}

double Camel::changeOfTime(int i) {
	if (i == 1) {
		return 5;
	}
	else {
		return 5 + (8 * (i - 1));
	}

}