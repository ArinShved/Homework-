#pragma once

#include "ground_vehicle.h"

class Camel : public GroundV {
public:
	TYPEOFVEHICLEAPI Camel();
	TYPEOFVEHICLEAPI double changeOfTime(int i) override;

};