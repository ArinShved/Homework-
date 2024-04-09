#pragma once

#include "air_vehicle.h"

class CarpetPlane : public AirV {
public:
	TYPE_OF_VEHICLE_API CarpetPlane();
	TYPE_OF_VEHICLE_API double changeOfDist(int distance) override;
};