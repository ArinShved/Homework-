#pragma once
#include <iostream>
#include <string>



#ifdef TYPE_OF_VEHICLE_EXPORTS
#define TYPE_OF_VEHICLE_API __declspec(dllexport)
#else
#define TYPE_OF_VEHICLE_API __declspec(dllimport)
#endif;


class GroundV{
protected:
	std::string name;
	int speed;
	double rest;
	int time_b_rest;

public:
	TYPE_OF_VEHICLE_API GroundV();
	TYPE_OF_VEHICLE_API virtual double changeOfTime(int i);
	TYPE_OF_VEHICLE_API void getName();
	TYPE_OF_VEHICLE_API virtual double race(int dist);
}; 