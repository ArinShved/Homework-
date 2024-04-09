#pragma once

#include <iostream>
#include <string>

#ifdef TYPE_OF_VEHICLE_EXPORTS
#define TYPE_OF_VEHICLE_API __declspec(dllexport)
#else
#define TYPE_OF_VEHICLE_API __declspec(dllimport)
#endif;



class AirV {
protected:
	double reduction;
	std::string name;
	int speed;
public:
	TYPE_OF_VEHICLE_API AirV();
	TYPE_OF_VEHICLE_API virtual double changeOfDist(int distance);
	TYPE_OF_VEHICLE_API void getName();
	TYPE_OF_VEHICLE_API virtual double race(int dist);
};