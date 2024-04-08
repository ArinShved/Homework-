#pragma once

#ifdef LEAVER_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif;



#include <iostream>
#include <string>

class Leaver {
private:
	std::string name;
public:
	LEAVER_API Leaver(std::string name);
	LEAVER_API void leave(std::string name);
};