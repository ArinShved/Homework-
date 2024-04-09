#pragma once
#include "ground_vehicle.h"

class Centaur : public GroundV {
public:
	TYPE_OF_VEHICLE_API Centaur();
	TYPE_OF_VEHICLE_API double race(int dist) override;
};