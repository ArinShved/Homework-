#include "functions.h"


void registration_mode3(std::vector<Vehicle>& member) {
	int n;
	static std::vector<int> num_of_n;
	bool stop;

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
				stop = 1;
				break;
			}
			stop = 0;
		}

		if (stop = 0) {
			switch (n) {
			case 1: {
				AllTerBoots all_ter_boots();
				//std::cout << all_ter_boots.getName() << "успешно зарегистрированы! ";
				member.emplace_back(all_ter_boots);

				break;
			}
			case 2: {
				Broom broom();
				member.emplace_back(broom);
			//	std::cout << broom.getName() << "успешно зарегистрированы! ";
				break;
			}
			case 3: {
				Camel camel();
				member.emplace_back(camel);
				//std::cout << camel.getName() << "успешно зарегистрированы! ";
				break;
			}
			case 4: {
				Centaur	centaur();
				member.emplace_back(centaur);
				//std::cout << centaur.getName() << "успешно зарегистрированы! ";
				break;
			}
			case 5: {
				Eagle eagle();
				member.emplace_back(eagle);
				//std::cout << eagle.getName() << "успешно зарегистрированы! ";
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
		}
		num_of_n.push_back(n);

}
void registration_mode2(std::vector<Vehicle>& member) {
	int n;
	std::vector<int> num_of_n;
	bool stop;

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
				stop = 1;
				break;
			}
			stop = 0;
		}

		if (stop = 0) {
			switch (n) {
			case 1: {
				std::cout << "успешно зарегистрированы! ";;

				break;
			}
			case 2: {
				Broom broom();
				member.emplace_back(broom);
				break;
			}
			case 3: {
				
				break;
			}
			case 4: {
				
				break;
			}
			case 5: {
				Eagle eagle();
				member.emplace_back(eagle);
				break;
			}
			case 6: {
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
		}
		num_of_n.push_back(n);
	} while (n != 0);

}

void registration_mode1(std::vector<Vehicle>& member) {
	int n;
	std::vector<int> num_of_n;
	bool stop;

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
				stop = 1;
				break;
			}
			stop = 0;
		}

		if (stop = 0) {
			switch (n) {
			case 1: {
				AllTerBoots all_ter_boots();
				std::cout << "успешно зарегистрированы! ";
				member.emplace_back(all_ter_boots);

				break;
			}
			case 2: {
				
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
				break;
			}
			case 6: {
				CamelSpB camel_sp();
				member.emplace_back(camel_sp);
				break;
			}
			case 7: {
				break;
			}
			case 0: {
				break;
			}
			default: {
				std::cout << "Ошибка! Неправильное число.";
			}
			}
		}
		num_of_n.push_back(n);
	} while (n != 0);

}