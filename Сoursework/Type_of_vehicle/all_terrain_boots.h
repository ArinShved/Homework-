#pragma once

#include "ground_vehicle.h"

class AllTerBoots : public GroundV {
public:
	TYPE_OF_VEHICLE_API AllTerBoots();
	TYPE_OF_VEHICLE_API double changeOfTime(int i) override;
};