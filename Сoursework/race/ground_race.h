#pragma once
#include "race.h"
#include "camel.h"
#include "camel_speedboad.h"
#include "centaur.h"
#include "all_terrain_boots.h"


class GroundRace : public Race {
public:
	GroundRace();
	GroundRace(int dist);
	void countTime(int dist, std::vector<Vehicle> member) override;
};