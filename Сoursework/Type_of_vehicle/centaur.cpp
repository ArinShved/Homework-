#include "centaur.h"

Centaur::Centaur() : GroundV() {
	this->name = "Кентавр";
	this->speed = 15;
	this->rest = 2;
	this->time_b_rest = 8;
}

double Centaur::race(int dist) {
	double temp = static_cast<double>(dist) / speed;
	int rest_num = dist / time_b_rest;
	return temp + (rest * rest_num);
}