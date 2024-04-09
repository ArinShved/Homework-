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
	std::vector<std::string> names = { " " , "1. �������-���������", "2. �����", "3. �������","4. �������", "5. ����", "6. �������-���������", "7. �����-�������" };
	std::vector<std::string> race_type = { "��������", "���������", "�������� � ���������" };
	int mode;
	do {
		std::vector<int> race_member;
		std::vector<std::string> member_name;
		std::vector<double> results;
		std::cout << "����� ���������� � �������� ���������!\n "
			<< "1. ����� ��� ��������� ����������\n "
			<< "2. ����� ��� ���������� ����������\n "
			<< "3. ����� ��� ��������� � ���������� ����������\n "
			<< "�������� ��� �����: ";
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
			std::cout << "������������ �����! ��������� �������! \n";
			system("pause");
			return 0;
			break;
		}
		}

		std::cout << "������� ����� ��������� (������ ���� �������������): ";
		std::cin >> distance;
		distance = abs(distance);

		std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������:\n ";
		int num_of_member = 0;

		do {
			if (num_of_member < 2) {
				std::cout << "1.  ���������������� ��������� \n" << "�������� ��������: ";
			}
			else
			{
				std::cout << "1. ���������������� ��������� \n" << "2. ������ �����\n " << "�������� ��������: ";
			}
			std::cin >> user_answer;
			if (user_answer != 1 && user_answer != 2) {
				std::cout << "������������ �����! \n";
			}
			if (user_answer == 1) {
				int j = mode - 1;
				std::cout << "\n����� " << race_type[j] << "\n";
				std::cout << "����������: " << distance << "\n";
				if (num_of_member < 1) {
					std::cout << " ";
				}
				else {
					std::cout << "������������������ ������������ ��������: ";
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

		std::cout << "\n���������� �����:\n";
		for (int i = 0; i < race_member.size(); i++) {
			std::cout << member_name[i] << " �����: " << results[i] << "\n";
			
		}

		std::cout << "\n\n1. �������� ��� ���� �����\n2. �����\n �������� ��������:\n ";
		std::cin >> user_answer;
	} while (user_answer != 2);

	system("pause");
	return 0;
}