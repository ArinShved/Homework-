#pragma once

#include "ground_vehicle.h"

class AllTerBoots : public GroundV {
public:
	AllTerBoots();
	double changeOfTime(int i) override;
};