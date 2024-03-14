#include <iostream>
#include <string>
#include <vector>
#include <fstream>


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
	};
	std::string getOutputAddress(){
		return city + ", " + street + ", " + std::to_string(houseNum) + ", " + std::to_string(flatNum);
	}
};

void sort(std::vector<std::string>& arr, int num)
{
	for (int i = 0; i < num; i++) {
		for (int j = i+1; j < num ; j++) {
			std::string str1 = arr[i];
			std::string str2 = arr[j];
			if (str1[0] >= str2[0]) {
				std::string str3 = arr[i];
				arr[i] = arr[j];
				arr[j] = str3;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int num = 0;
	std::vector<std::string> arr;
	std::ifstream file("in.txt");
	if (file.is_open()) {
		file >> num;
		for (int i = 0; i < num; i++) {
			std::string city, street;
			int houseNum, flatNum;
			file >> city;
			file >> street;
			file >> houseNum;
			file >> flatNum;
			Address address(city, street, houseNum, flatNum);
			arr.push_back(address.getOutputAddress());
		}
	}
	file.close();
	
	sort(arr, num);
	std::ofstream out("out.txt");
	if (out.is_open()) {
		out << num << "\n";
		for (int i = 0; i < num; i++) {
			out << arr[i] << "\n";
		}
	}
	out.close();
	
	return 0;
}