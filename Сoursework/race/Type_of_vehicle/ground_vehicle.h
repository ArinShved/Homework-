#pragma once
#include <iostream>
#include <string>

#include "vehicle.h"

class GroundV : public Vehicle{
protected:
	double rest;
	int time_b_rest;
	
public:
	GroundV();
	virtual double changeOfTime(int i);
	double race(int dist) override;
	
};