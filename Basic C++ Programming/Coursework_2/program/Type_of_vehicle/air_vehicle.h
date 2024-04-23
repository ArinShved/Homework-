#pragma once

#include <iostream>
#include <string>

#ifdef TYPEOFVEHICLE_EXPORTS
#define TYPEOFVEHICLEAPI __declspec(dllexport)
#else
#define TYPEOFVEHICLEAPI __declspec(dllimport)
#endif;



class AirV {
protected:
	double reduction;
	std::string name;
	int speed;
public:
	TYPEOFVEHICLEAPI AirV();
	TYPEOFVEHICLEAPI virtual double changeOfDist(int distance);
	TYPEOFVEHICLEAPI void getName();
	TYPEOFVEHICLEAPI virtual double race(int dist);
};