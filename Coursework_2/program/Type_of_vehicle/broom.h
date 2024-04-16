#pragma once

#include "air_vehicle.h"

class Broom : public AirV {
public:
	TYPEOFVEHICLEAPI Broom();
	TYPEOFVEHICLEAPI double changeOfDist(int dist) override;
};