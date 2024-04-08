#include <iostream>



#include "ground_race.h"
#include "race.h"
#include "air_race.h"
#include "functions.h"


int main() {
	int user_answer;
	int distance;
	std::vector<Vehicle> member{};


	std::cout << "����� ���������� � �������� ���������!\n "
		<< "1. ����� ��� ��������� ����������\n "
		<< "2. ����� ��� ���������� ����������\n "
		<< "3. ����� ��� ��������� � ���������� ����������\n "
		<< "�������� ��� �����: ";
	std::cin >> user_answer;
	std::cout << "������� ����� ��������� (������ ���� �������������): ";
	std::cin >> distance;
	

	auto user_race = chooseRaceType(user_answer, distance);

std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������: ";
int num_of_member = 0;

while (user_answer != 2) {
	if (num_of_member < 2) {
		std::cout << "1.  ���������������� ��������� \n" << "�������� ��������: ";
	}
	else
	{
		std::cout << "1. ���������������� ��������� \n" << "2. ������ �����\n " << "�������� ��������: ";
	}
	std::cin >> user_answer;
	if (user_answer == 1) {
		std::cout << "����� ��� " << user_race.getName() << "\n";
		std::cout << "����������: " << distance << "\n";
		if (num_of_member > 0) {
			std::cout << " ";
		}
		else {
			std::cout << "������������������ ������������ ��������: ";
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