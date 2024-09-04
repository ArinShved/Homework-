#include "class.h"


	Data::Data(int num) : number(num) {};

	int Data::get_number() const {
		return number;
	}

	void Data::set_value(int value) {
		number = value;
	}

