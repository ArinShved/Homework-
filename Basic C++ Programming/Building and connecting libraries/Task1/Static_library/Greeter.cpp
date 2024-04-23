#include "Greeter.h"


Greeter::Greeter(std::string name) {
	this->name = name;
}
void Greeter::greet(std::string name) {
	std::cout << "Здравствуйте,  " << name << "!\n";
}