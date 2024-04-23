#pragma once
#include <iostream>
#include <string>



#ifdef TYPEOFVEHICLE_EXPORTS
#define TYPEOFVEHICLEAPI __declspec(dllexport)
#else
#define TYPEOFVEHICLEAPI __declspec(dllimport)
#endif;


class GroundV{
protected:
	std::string name;
	int speed;
	double rest;
	int time_b_rest;

public:
	TYPEOFVEHICLEAPI GroundV();
	TYPEOFVEHICLEAPI virtual double changeOfTime(int i);
	TYPEOFVEHICLEAPI void getName();
	TYPEOFVEHICLEAPI virtual double race(int dist);
}; 