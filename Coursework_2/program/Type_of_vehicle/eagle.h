#pragma once

#include "air_vehicle.h"

class Eagle : public AirV {
public:
	TYPEOFVEHICLEAPI Eagle();
	TYPEOFVEHICLEAPI double changeOfDist(int dict) override;
};