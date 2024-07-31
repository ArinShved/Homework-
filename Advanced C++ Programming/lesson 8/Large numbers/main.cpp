#include <iostream>
#include <string>
#include <vector>

class big_integer {
private:
	std::string number;
	std::vector<int> arr;
public: 
	big_integer(const std::string& num) : number(num) {
		for (size_t i = 0; i < num.length(); i++) {
			arr.push_back(num[i] - '0');
			
		}
		std::reverse(arr.begin(), arr.end());
	}

	big_integer(big_integer&& other) noexcept : number(std::exchange(other.number, nullptr)) {}

	big_integer& operator=(big_integer&& other) noexcept {
		if (this != &other) {
			number = std::move(other.number);
		}
		return *this;
	}

	std::string operator+(const big_integer& other) const {
		int size;
		arr.size() > other.arr.size() ? size = arr.size() : size = other.arr.size();
		std::vector<int> temp(size + 2);
		temp = arr;
		for (size_t i = 0; i < other.arr.size(); i++) {
			temp[i] += other.arr[i];
			if (temp[i] > 9) {
				temp[i] %= 10;
				temp[i + 1]++;
			}
		}
		for (size_t i = 0; i < size - 1; i++) {
			if (temp[i] > 9) {
				temp[i] %= 10;
				temp[i + 1]++;
			}
		}

		std::reverse(temp.begin(), temp.end());
		std::string result;
		for (size_t i = 0; i < temp.size(); i++) {
			result += std::to_string(temp[i]);
		}
		return result;

	}

	std::string operator*(int num) {
	
		std::vector<int> a;
		for (int i = number.length(); i > 0; i -= 9) {
			if (i < 9) {
				a.push_back(atoi(number.substr(0, i).c_str()));
			}
			else {
				a.push_back(atoi(number.substr(i - 9, 9).c_str()));
			}
		}
		while (a.size() > 1 && a.back() == 0) {
			a.pop_back();
		}

		int carry = 0;
		const int base = 1e9;
		std::string result;

		for (size_t i = 0; i < a.size() || carry; ++i) {
			if (i == a.size()) {
				a.push_back(0);
			}
			long long cur = carry + a[i] * 1ll * num;
			a[i] = int(cur % base);
			carry = int(cur / base);
		}
		while (a.size() > 1 && a.back() == 0) {
			a.pop_back();
		}
		for (auto i = (int)a.size() - 1; i >= 0; --i) {
			result += std::to_string(a[i]);
		}

		return result;
	}
	
};

int main() {

	auto number1 = big_integer("999999999999999999999999999999999999999");
	auto number2 = big_integer("785248765");
	
	auto result = number1 + number2;
	std::cout << result << "\n";
	auto result_2 = number1 * 56;
	std::cout << result_2 << "\n";

	return 0;
}