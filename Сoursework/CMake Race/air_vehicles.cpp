#include "air_vehicle.h"

AirV::AirV() : Vehicle() {
	name = "Воздушный транспорт";
	speed = 0;
	reduction = 0;
}

double AirV::changeOfDist(int distance) {
	return reduction * (1 - distance);
}

double AirV::race(int dist) {
	double temp = changeOfDist(dist);
	return temp / speed;
}
