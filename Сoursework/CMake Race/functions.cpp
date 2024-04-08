#include "functions.h"


void registration_mode3(std::vector<Vehicle>& member) {
	int n;
	static std::vector<int> num_of_n;
	bool stop;

		std::cout << "1. �������-��������� \n"
			<< "2. �����\n"
			<< "3. �������\n"
			<< "4. �������\n"
			<< "5. ����\n"
			<< "6. �������-���������\n"
			<< "7. �����-�������\n"
			<< "0. ��������� �����������\n";
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";

		std::cin >> n;
		for (int i = 0; n < num_of_n.size(); i++) {
			if (n == num_of_n[i]) {
				std::cout << "������ �������� ��� ���������������! ";
				stop = 1;
				break;
			}
			stop = 0;
		}

		if (stop = 0) {
			switch (n) {
			case 1: {
				AllTerBoots all_ter_boots();
				//std::cout << all_ter_boots.getName() << "������� ����������������! ";
				member.emplace_back(all_ter_boots);

				break;
			}
			case 2: {
				Broom broom();
				member.emplace_back(broom);
			//	std::cout << broom.getName() << "������� ����������������! ";
				break;
			}
			case 3: {
				Camel camel();
				member.emplace_back(camel);
				//std::cout << camel.getName() << "������� ����������������! ";
				break;
			}
			case 4: {
				Centaur	centaur();
				member.emplace_back(centaur);
				//std::cout << centaur.getName() << "������� ����������������! ";
				break;
			}
			case 5: {
				Eagle eagle();
				member.emplace_back(eagle);
				//std::cout << eagle.getName() << "������� ����������������! ";
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
				std::cout << "������! ������������ �����.";
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
		std::cout << "1. �������-��������� \n"
			<< "2. �����\n"
			<< "3. �������\n"
			<< "4. �������\n"
			<< "5. ����\n"
			<< "6. �������-���������\n"
			<< "7. �����-�������\n"
			<< "0. ��������� �����������\n";
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";

		std::cin >> n;
		for (int i = 0; n < num_of_n.size(); i++) {
			if (n == num_of_n[i]) {
				std::cout << "������ �������� ��� ���������������! ";
				stop = 1;
				break;
			}
			stop = 0;
		}

		if (stop = 0) {
			switch (n) {
			case 1: {
				std::cout << "������� ����������������! ";;

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
				std::cout << "������! ������������ �����.";
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
		std::cout << "1. �������-��������� \n"
			<< "2. �����\n"
			<< "3. �������\n"
			<< "4. �������\n"
			<< "5. ����\n"
			<< "6. �������-���������\n"
			<< "7. �����-�������\n"
			<< "0. ��������� �����������\n";
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";

		std::cin >> n;
		for (int i = 0; n < num_of_n.size(); i++) {
			if (n == num_of_n[i]) {
				std::cout << "������ �������� ��� ���������������! ";
				stop = 1;
				break;
			}
			stop = 0;
		}

		if (stop = 0) {
			switch (n) {
			case 1: {
				AllTerBoots all_ter_boots();
				std::cout << "������� ����������������! ";
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
				std::cout << "������! ������������ �����.";
			}
			}
		}
		num_of_n.push_back(n);
	} while (n != 0);

}