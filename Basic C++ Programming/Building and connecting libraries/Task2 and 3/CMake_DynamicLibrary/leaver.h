#pragma once


#include <iostream>
#include <string>

class Leaver {
private:
	std::string name;
public:
	 Leaver(std::string name);
	 void leave(std::string name);
};