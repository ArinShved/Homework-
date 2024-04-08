#pragma once

#include "ground_vehicle.h"

class Camel : public GroundV {
public:
	Camel();
	double changeOfTime(int i) override;
	
};