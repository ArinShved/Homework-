#include "function.h"


void registration(std::vector<int>& race_member, std::vector<std::string>& members_name, std::vector<int> member, std::vector<std::string> name, bool& start) {
	bool stop = 0;
	int n;

	std::cout 
		<< "\n\n1. �������-��������� \n"
		<< "2. �����\n"
		<< "3. �������\n"
		<< "4. �������\n"
		<< "5. ����\n"
		<< "6. �������-���������\n"
		<< "7. �����-�������\n"
		<< "0. ��������� �����������\n";
	std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";

	std::cin >> n;

	

	for(int i = 0; i < member.size(); i++){
		if (n == member[i]){
			stop = 1;
		}
	}

	for (int i = 0; i < race_member.size(); i++) {
		if (n == race_member[i]) {
			std::cout << "\n\n������ �������� ��� ���������������!\n\n ";
			stop = 0;
			break;
		}
	}
	
	if (n == 0) {
		std::cout << "\n";
		start = 0;
	
	}
	else if (stop == 1) {
		race_member.push_back(n);
		members_name.push_back(name[n]);
		std::cout << name[n] << " ���������������!\n\n";
	}
	else {
		std::cout << "\n\n������ ����������������!\n\n";
	}

}
