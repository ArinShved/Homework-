#include "broom.h"

Broom::Broom() :AirV() {
	name = "Метла ";
	speed = 20;
	reduction = 0;
}

double Broom::changeOfDist(int dist) {
	int temp = dist;
	while (temp > 0) {
		temp -= 1000;
		reduction += 0.01;
	}
	return dist * (1 - reduction);

}
