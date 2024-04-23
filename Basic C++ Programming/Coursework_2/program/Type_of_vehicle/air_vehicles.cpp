#include "air_vehicle.h"

AirV::AirV() {
	this->name = "Воздушный транспорт";
	this->speed = 0;
	this->reduction = 0;
}

double AirV::changeOfDist(int distance) {
	return reduction * (1 - distance);
}

double AirV::race(int dist) {
	double temp = changeOfDist(dist);
	return temp / speed;
}
void AirV::getName() {
	std::cout << name;
}