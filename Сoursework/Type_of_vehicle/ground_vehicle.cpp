#include "ground_vehicle.h"

GroundV::GroundV() {
	this->name = "Наземный транспорт";
	this->speed = 0;
	this->rest = 0;
	this->time_b_rest = 0;
}

double GroundV::changeOfTime(int i) {
	if (i == 1) {
		rest = 0;
	}
	return 0;
}

double GroundV::race(int dist) {
	double temp = static_cast<double>(dist) / speed;
	int rest_num = dist / time_b_rest;
	return temp + changeOfTime(rest_num);
}
void GroundV::getName() {
	std::cout << name;
}

