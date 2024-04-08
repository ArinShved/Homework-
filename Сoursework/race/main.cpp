#include <iostream>



#include "ground_race.h"
#include "race.h"
#include "air_race.h"
#include "functions.h"


int main() {
	int user_answer;
	int distance;
	std::vector<Vehicle> member{};


	std::cout << "Добро пожаловать в гоночный симулятор!\n "
		<< "1. Гонка для наземного транспорта\n "
		<< "2. Гонка для воздушного транспорта\n "
		<< "3. Гонка для наземного и воздушного транспорта\n "
		<< "Выберите тип гонки: ";
	std::cin >> user_answer;
	std::cout << "Укажите длину дистанции (должна быть положительной): ";
	std::cin >> distance;
	

	auto user_race = chooseRaceType(user_answer, distance);

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
		std::cout << "Гонка для " << user_race.getName() << "\n";
		std::cout << "Расстояние: " << distance << "\n";
		if (num_of_member > 0) {
			std::cout << " ";
		}
		else {
			std::cout << "Зарегистрированные транспортные средства: ";
			for (int i = 0; i < num_of_member; i++) {
				member[i].getName();
			}
		}
		user_race.registration(member);


	}
}





	system("pause");
	return 0;
}