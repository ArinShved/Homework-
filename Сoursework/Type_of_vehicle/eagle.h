#pragma once

#include "air_vehicle.h"

class Eagle : public AirV {
public:
	TYPE_OF_VEHICLE_API Eagle();
	TYPE_OF_VEHICLE_API double changeOfDist(int dict) override;
};