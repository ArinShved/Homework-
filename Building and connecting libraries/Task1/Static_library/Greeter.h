#pragma once


#include <iostream>
#include <string>


class Greeter {
private:
	std::string name;
public:
	Greeter(std::string name);
	void greet(std::string name);
};