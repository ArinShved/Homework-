#pragma once
#include "ground_vehicle.h"

class Centaur : public GroundV {
public:
	Centaur();
	double race(int dist) override;
};