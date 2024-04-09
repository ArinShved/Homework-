#include "eagle.h"

Eagle::Eagle() : AirV() {
	this->name = "Îð¸ë";
	this->speed = 8;
	this->reduction = 0.06;
}

double Eagle::changeOfDist(int dist) {
	return dist * (1 - reduction);
}