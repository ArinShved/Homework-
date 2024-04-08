#pragma once

#include <iostream>
#include <string>

#include "vehicle.h"


class AirV: public Vehicle {
protected:
	double reduction;
public:
	AirV();
	virtual double changeOfDist(int distance);
    double race(int dist) override;
};