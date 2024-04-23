#include "leaver.h"


Leaver::Leaver(std::string name) {
	this->name = name;
}
void Leaver::leave(std::string name) {
	
	std::cout << "До свидания, " << name << "!\n";
}