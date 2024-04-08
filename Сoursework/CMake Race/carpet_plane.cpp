#include "carpet_plane.h"

CarpetPlane::CarpetPlane() : AirV() {
	name = "Ковёр-самолёт";
	speed = 10;
	reduction = 0;
}

double CarpetPlane::changeOfDist(int distance) {
	if (distance < 1000) {
		return distance;
	}
	else if (distance < 5000) {
		reduction = 0.03;
		return distance * (1 - reduction);
	}
	else if (distance < 10000) {
		reduction = 0.1;
		return distance * (1 - reduction);
	}
	else {
		reduction = 0.05;
		return distance * (1 - reduction);
	}
}