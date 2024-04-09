#pragma once

#include "air_vehicle.h"

class Broom : public AirV {
public:
	TYPE_OF_VEHICLE_API Broom();
	TYPE_OF_VEHICLE_API double changeOfDist(int dist) override;
};