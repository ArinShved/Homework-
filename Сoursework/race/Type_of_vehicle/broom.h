#pragma once

#include "air_vehicle.h"

class Broom : public AirV {
public:
	Broom();
	double changeOfDist(int dist) override;
};