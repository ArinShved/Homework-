#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "function.h"


int main() {
	setlocale(LC_ALL, "rus");

	int user_answer;
	int distance = 0;
	std::vector<int> member = { 1, 2, 3, 4, 5, 6, 7};
	std::vector<int> gr_member = { 1, 3, 4, 6};
	std::vector<int> air_member= { 2, 5, 7};
	std::vector<std::string> names = { " " , "1. Ботинки-вездеходы", "2. Метла", "3. Верблюд","4. Кентавр", "5. Орел", "6. Верблюд-быстроход", "7. Ковер-самолет" };
	std::vector<std::string> race_type = { "наземная", "воздушная", "наземная и воздушная" };
	int mode;
	do {
		std::vector<int> race_member;
		std::vector<std::string> member_name;
		std::vector<double> results;
		std::cout << "Добро пожаловать в гоночный симулятор!\n "
			<< "1. Гонка для наземного транспорта\n "
			<< "2. Гонка для воздушного транспорта\n "
			<< "3. Гонка для наземного и воздушного транспорта\n "
			<< "Выберите тип гонки: ";
		std::cin >> user_answer;

		switch (user_answer) {
		case 1: {
			mode = 1;
			break;
		}
		case 2: {
			mode = 2;
			break;
		}
		case 3: {
			mode = 3;
			break;
		}
		default:
		{
			std::cout << "Неправильное число! Повторите попытку! \n";
			system("pause");
			return 0;
			break;
		}
		}

		std::cout << "Укажите длину дистанции (должна быть положительной): ";
		std::cin >> distance;
		distance = abs(distance);

		std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства:\n ";
		int num_of_member = 0;

		do {
			if (num_of_member < 2) {
				std::cout << "1.  Зарегистрировать транспорт \n" << "Выберите дейтсвие: ";
			}
			else
			{
				std::cout << "1. Зарегистрировать транспорт \n" << "2. Начать гонку\n " << "Выберите дейтсвие: ";
			}
			std::cin >> user_answer;
			if (user_answer != 1 && user_answer != 2) {
				std::cout << "Неправильное число! \n";
			}
			if (user_answer == 1) {
				int j = mode - 1;
				std::cout << "\nГонка " << race_type[j] << "\n";
				std::cout << "Расстояние: " << distance << "\n";
				if (num_of_member < 1) {
					std::cout << " ";
				}
				else {
					std::cout << "Зарегистрированные транспортные средства: ";
					for (int i = 0; i < member_name.size(); i++) {
						std::cout << member_name[i] << ", ";
					}
				}
				if (mode == 1) {
					registration(race_member, member_name, gr_member, names);
				}
				else if (mode == 2) {
					registration(race_member, member_name, air_member, names);
				}
				else {
					registration(race_member, member_name, member, names);
				}
				num_of_member = race_member.size();
			}
		} while (user_answer != 2);
		

		for (int i = 0; i < race_member.size(); i++) {
			if (race_member[i] == 1) {
				AllTerBoots boot;
				results.push_back(boot.race(distance));
			}
			else if (race_member[i] == 2) {
				Broom broom;
				results.push_back(broom.race(distance));
			}
			else if (race_member[i] == 3) {
				Camel camel;
				results.push_back(camel.race(distance));
			}
			else if (race_member[i] == 4) {
				Centaur centaur;
				results.push_back(centaur.race(distance));
			}
			else if (race_member[i] == 5) {
				Eagle eagle;
				results.push_back(eagle.race(distance));
			}
			else if (race_member[i] == 6) {
				CamelSpB camel_sp;
				results.push_back(camel_sp.race(distance));
			}
			else if (race_member[i] == 7) {
				CarpetPlane carpet;
				results.push_back(carpet.race(distance));
			}
		
		}


		for (int i = 0; i < race_member.size(); i++) {
			for (int j = 0; j < race_member.size()-1; j++) {
				if (results[j] > results[j + 1]) {
					double temp = results[j];
					results[j] = results[j + 1];
					results[j + 1] = temp;

					std::string name_temp = member_name[j];
					member_name[j] = member_name[j + 1];
					member_name[j + 1] = name_temp;
				}
			}
		}

		std::cout << "\nРезультаты гонки:\n";
		for (int i = 0; i < race_member.size(); i++) {
			std::cout << member_name[i] << " Время: " << results[i] << "\n";
			
		}

		std::cout << "\n\n1. Провести еще одну гонку\n2. Выйти\n Выберите дейтсвие:\n ";
		std::cin >> user_answer;
	} while (user_answer != 2);

	system("pause");
	return 0;
}