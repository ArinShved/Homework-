#pragma once
#include <string>
#include <iostream>

class Vehicle {
protected:
	std::string name;
	int speed;
	
public:
	Vehicle();
	void getName();
	virtual double race(int dist);
};