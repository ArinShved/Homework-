#pragma once
#include <vector>
#include <iostream>

#include "vehicle.h"
#include "broom.h"
#include "carpet_plane.h"
#include "eagle.h"
#include "camel.h"
#include "camel_speedboad.h"
#include "centaur.h"
#include "all_terrain_boots.h"


class Race {
protected:
	std::vector<Vehicle> members;
	int distance;
	std::vector<int> time;
public:
	Race();
	Race(int distance);
	virtual void countTime(int dist, std::vector<Vehicle> member);
	virtual void registration(std::vector<Vehicle>& memeber);


};