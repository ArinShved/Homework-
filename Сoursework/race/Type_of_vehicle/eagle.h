#pragma once

#include "air_vehicle.h"

class Eagle : public AirV {
public:
	Eagle();
	double changeOfDist(int dict) override;
};