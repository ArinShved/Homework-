#include "broom.h"

Broom::Broom() :AirV() {
	this->name = "Метла ";
	this->speed = 20;
	this->reduction = 0;
}

double Broom::changeOfDist(int dist) {
	int temp = dist;
	while (temp >= 1000) {
		temp -= 1000;
		reduction += 0.01;
	}
	return dist * (1 - reduction);

}
