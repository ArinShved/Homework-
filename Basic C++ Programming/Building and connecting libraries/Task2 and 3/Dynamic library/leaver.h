#pragma once

#ifdef DYNAMICLIBRARY_EXPORTS
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif;

#include <iostream>
#include <string>

class Leaver {
private:
	std::string name;
public:
	DYNAMICLIBRARY_API Leaver(std::string name);
	DYNAMICLIBRARY_API void leave(std::string name);
};