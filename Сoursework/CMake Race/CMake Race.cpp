

#include "CMake Race.h"
#include <iostream>
#include <string>
#include <vector>

#include "functions.h"


int main() {
	int user_answer;
	int distance;
	std::vector<Vehicle> member{};
	std::vector<std::string> race_type = { "наземная", "воздушная", "наземная и воздушная" };
	int mode;
	do {
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
			// выкини ошибку
		}
		std::cout << "Укажите длину дистанции (должна быть положительной): ";
		std::cin >> distance;


		std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства: ";
		int num_of_member = 0;

		while (user_answer != 2) {
			if (num_of_member < 2) {
				std::cout << "1.  Зарегистрировать транспорт \n" << "Выберите дейтсвие: ";
			}
			else
			{
				std::cout << "1. Зарегистрировать транспорт \n" << "2. Начать гонку\n " << "Выберите дейтсвие: ";
			}
			std::cin >> user_answer;
			if (user_answer == 1) {
				int i = mode - 1;
				std::cout << "Гонка для " << race_type[i] << "\n";
				std::cout << "Расстояние: " << distance << "\n";
				if (num_of_member < 1) {
					std::cout << " ";
				}
				else {
					std::cout << "Зарегистрированные транспортные средства: ";
					for (int i = 0; i < num_of_member; i++) {
						member[i].getName();
					}
				}
				if (mode == 1) {
					registration_mode1(member);
				}
				else if (mode == 2) {
					registration_mode2(member);
				}
				else {
					registration_mode3(member);
				}
				num_of_member++;
			}
		}
		}

		std::cout << "Результаты гонки:\n";
		for (int i = 0; i < member.size(); i++) {
			member[i].getName();
			std:: cout << " " << member[i].race(distance);
		}

		std::cout << " ";
		std::cin >> user_answer;
	} while (user_answer != 2);

	system("pause");
	return 0;
}

