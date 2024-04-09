#pragma once

#include "ground_vehicle.h"

class Camel : public GroundV {
public:
	TYPE_OF_VEHICLE_API Camel();
	TYPE_OF_VEHICLE_API double changeOfTime(int i) override;

};