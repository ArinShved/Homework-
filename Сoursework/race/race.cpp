#include "race.h"

Race::Race(int distance) {
	this->distance = distance;
}

Race::Race() {
	distance = 0;
}

void Race::countTime(int dist, std::vector<Vehicle> member) {
	for (int i = 0; i < member.size(); i++) {
		int temp = dist;
		
		member[i].time = temp;
	}
}

void Race::registration(std::vector<Vehicle>& member) {
	int n;
	std::vector<int> num_of_n;

	do {
		std::cout << "1. Ботинки-вездеходы \n"
			<< "2. Метла\n"
			<< "3. Верблюд\n"
			<< "4. Кентавр\n"
			<< "5. Орел\n"
			<< "6. Верблюд-быстроход\n"
			<< "7. Ковер-самолет\n"
			<< "0. Закончить регистрацию\n";
		std::cout << "Выберете транспорт или 0 для окончания процесса регистрации: ";

		std::cin >> n;
		for (int i = 0; n < num_of_n.size(); i++) {
			if (n == num_of_n[i]) {
				std::cout << "Данный участник уже зарегистрирован! ";
				break;
			}
		}
		switch (n) {
		case 1: {
			AllTerBoots all_ter_boots();
			std::cout << "успешно зарегистрированы! ";
			member.emplace_back(all_ter_boots);
			
			break;
		}
		case 2: {
			Broom broom();
			member.emplace_back(broom);
			break;
		}
		case 3: {
			Camel camel();
			member.emplace_back(camel);
			break;
		}
		case 4: {
			Centaur	centaur();
			member.emplace_back(centaur);
			break;
		}
		case 5: {
			Eagle eagle();
			member.emplace_back(eagle);
			break;
		}
		case 6: {
			CamelSpB camel_sp();
			member.emplace_back(camel_sp);
			break;
		}
		case 7: {
			CarpetPlane carpet_plane();
			member.emplace_back(carpet_plane);
			break;
		}
		case 0: {
			break;
		}
		default: {
			std::cout << "Ошибка! Неправильное число.";
		}
		}
	} while (n != 0);

}



