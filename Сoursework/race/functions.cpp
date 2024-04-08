#include "functions.h"


 auto chooseRaceType(int user_answer, int distance) {
	switch (user_answer) {
	case 1: {
		GroundRace race1(distance);
		return race1;
		break;
	}
	case 2: {
		AirRace race2(distance);
		return race2;
		break;
	}
	case 3: {
		Race race3(distance);
		return race3;
		break;
	}
	default: {
		std::cout << "Ошибка! Неправильное число. ";
		break;
	}
	}
}

