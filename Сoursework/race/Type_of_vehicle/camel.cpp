#include "camel.h"

Camel::Camel() :GroundV() {
	name = "Верблюд";
	speed = 10;
	rest = 5;
	time_b_rest = 30;
}

double Camel::changeOfTime(int i) {
	if (i == 1) {
		return 5;
	}
	else {
		return 5 + (8 * (i-1));
	}

}