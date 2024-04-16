#pragma once

#include "ground_vehicle.h"

class AllTerBoots : public GroundV {
public:
	TYPEOFVEHICLEAPI AllTerBoots();
	TYPEOFVEHICLEAPI double changeOfTime(int i) override;
};