#include "centaur.h"

Centaur::Centaur() : GroundV() {
	name = "Кентавр";
	speed = 15;
	rest = 2;
	time_b_rest = 8;
}

double Centaur::race(int dist) {
	double temp = static_cast<double>(dist) / speed;
	int rest_num = dist / time_b_rest;
	return temp + (rest * rest_num);
}