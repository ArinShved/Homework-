#include "function.h"


void registration(std::vector<int>& race_member, std::vector<std::string>& members_name, std::vector<int> member, std::vector<std::string> name, bool& start) {
	bool stop = 0;
	int n;

	std::cout 
		<< "\n\n1. Ботинки-вездеходы \n"
		<< "2. Метла\n"
		<< "3. Верблюд\n"
		<< "4. Кентавр\n"
		<< "5. Орел\n"
		<< "6. Верблюд-быстроход\n"
		<< "7. Ковер-самолет\n"
		<< "0. Закончить регистрацию\n";
	std::cout << "Выберете транспорт или 0 для окончания процесса регистрации: ";

	std::cin >> n;

	

	for(int i = 0; i < member.size(); i++){
		if (n == member[i]){
			stop = 1;
		}
	}

	for (int i = 0; i < race_member.size(); i++) {
		if (n == race_member[i]) {
			std::cout << "\n\nДанный участник уже зарегистрирован!\n\n ";
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
		std::cout << name[n] << " зарегистрирован!\n\n";
	}
	else {
		std::cout << "\n\nНельзя зарегистрировать!\n\n";
	}

}
