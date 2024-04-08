#include "all_terrain_boots.h"

AllTerBoots::AllTerBoots() : GroundV(){
	name = "Ботинки-вездеходы";
	speed = 6;
	rest = 10;
	time_b_rest = 60;
}

double AllTerBoots::changeOfTime(int i) {
	if (i == 1) {
		return 10;
	}
	else {
		return 10 + (5 * (i-1));
	}
}