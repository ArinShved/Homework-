#pragma once
#include "ground_vehicle.h"

class Centaur : public GroundV {
public:
	TYPEOFVEHICLEAPI Centaur();
	TYPEOFVEHICLEAPI double race(int dist) override;
};