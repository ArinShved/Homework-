#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Address {
private:
	std::string num;
	std::vector<std::string> city;
	std::vector<std::string> street;
	std::vector<std::string> houseNum;
	std::vector<std::string> flatNum;
public:
	Address(std::string fileName){ 
		std::ifstream file(fileName);
		if (file.is_open()) {
			file >> num;
			for (int i = 0; i < std::stoi(num); i++) {
				std::string a, a1, a2, a3;
				file >> a;
				file >> a1;
				file >> a2;
				file >> a3;;
				city.push_back(a);
				street.push_back(a1);
				houseNum.push_back(a2);
				flatNum.push_back(a3);
			}
		}
		file.close();

	}

	void writeInFile(std::string fileName){
		std::ofstream file;
		file.open(fileName);
		if (file.is_open()) {
			file << num << "\n";
			for (int i = std::stoi(num) - 1; i >= 0; i--) {
				file << city[i] << ", " << street[i] << ", " << houseNum[i] << ", " << flatNum[i] << "\n";
			}
		}
		file.close();
	}

};


int main(){

	Address address("in.txt");
	address.writeInFile("out.txt");

	return 0;
}
