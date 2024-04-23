#pragma once

#include "air_vehicle.h"

class CarpetPlane : public AirV {
public:
	TYPEOFVEHICLEAPI CarpetPlane();
	TYPEOFVEHICLEAPI double changeOfDist(int distance) override;
};