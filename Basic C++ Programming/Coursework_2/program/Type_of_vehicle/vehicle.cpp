#include "vehicle.h"

Vehicle::Vehicle() {
	name = "��������� ";
	speed = 0;
}
void Vehicle::getName() {
	std::cout << name;
}

double Vehicle::race(int dist) {
	return static_cast<double>(dist) / speed;
}