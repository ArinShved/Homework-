#include "eagle.h"

Eagle::Eagle() : AirV() {
	name = "���";
	speed = 8;
	reduction = 0.06;
}

double Eagle::changeOfDist(int dist) {
	return dist * (1 - reduction);
}