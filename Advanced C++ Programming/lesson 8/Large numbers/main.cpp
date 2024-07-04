#include <iostream>
#include <string>

class big_integer {
private:
	std::string number;
public: 
	big_integer( const std::string& num) : number(num) {}

	big_integer(big_integer&& other) noexcept : number(std::exchange(other.number, nullptr)) {}

	big_integer& operator=(big_integer&& other) noexcept {
		if (this != &other) {
			number = std::move(other.number);
		}
		return *this;
	}

	std::string operator+(const big_integer& other) const {
		std::string result = std::to_string(stoll(number) + stoll(other.number));
		return result;
	}
	
	std::string operator*(int num) const {
		std::string result = std::to_string(stoll(number) * num);
		return result;
	}
	
};

int main() {

	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");
	auto result = number1 + number2;
	std::cout << result; 

	return 0;
}