#pragma once

#include <iostream>
#include <string>

class Figure {
public:
	Figure();
	    std::string const getName();
		virtual void print();
protected:
	int numOfSides;
	std::string name;

};