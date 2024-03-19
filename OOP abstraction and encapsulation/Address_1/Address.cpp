#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Address {
private:
	std::string city;
	std::string street;
	int houseNum;
	int flatNum;
public:
	Address(std::string city, std::string street, int houseNum, int flatNum) {
		this->city = city;
		this->street = street;
		this->houseNum = houseNum;
		this->flatNum = flatNum;
	}
	std::string getAddress()
	{
		return city + ", " + street + ", " + std::to_string(houseNum) + ", " + std::to_string(flatNum) + "\n";
	}
};

void writeToFile(std::string fileName, std::vector<Address> allAddresses, int num){
	std::ofstream file_2;
	file_2.open(fileName);
	if (file_2.is_open()) {
		file_2 << num << "\n";
		for (int i = num - 1; i >= 0; i--) {
			file_2 << allAddresses[i].getAddress();
		}
	}
	file_2.close();
}


int main(){
	int num = 0;
	
	std::vector<Address> allAddresses{};
	std::ifstream file("in.txt");
	if (file.is_open()) {
		file >> num;
		for(int i = 0; i < num; i++){
		    std::string city, street;
			int houseNum, flatNum;
	    	file >> city;
		    file >> street;
		    file >> houseNum;
	    	file >> flatNum;
	    	Address address(city, street, houseNum, flatNum);
	    	allAddresses.push_back(address);
		}
		file.close();
	}

	
	writeToFile("out.txt", allAddresses, num);

	return 0;
}
