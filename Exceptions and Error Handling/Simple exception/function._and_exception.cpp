#include <string>

#include "function_and_exception.h"

const char* BadLength::what() const {
	return "Вы ввели слово запретной длины! До свидания.";
}

int function(std::string str, int forbidden_length) {
	if (str.size() != forbidden_length) {
		return str.size();
	}
	else {
		throw BadLength();
	}
}