#include "all_terrain_boots.h"

AllTerBoots::AllTerBoots() : GroundV() {
	this->name = "Ботинки-вездеходы";
	this->speed = 6;
	this->rest = 10;
	this->time_b_rest = 60;
}

double AllTerBoots::changeOfTime(int i) {
	if (i == 1) {
		return 10;
	}
	else {
		return 10 + (5 * (i - 1));
	}
}