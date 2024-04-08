#pragma once

#include "air_vehicle.h"

class CarpetPlane : public AirV {
public:
	CarpetPlane();
	double changeOfDist(int distance) override;
};