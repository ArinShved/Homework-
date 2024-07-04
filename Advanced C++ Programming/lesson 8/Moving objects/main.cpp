#include <iostream>
#include <vector>
#include <string>

template<class T>
std::vector<T> move_vectors(std::vector<T>& two, std::vector<T>& one) {
	two = std::move(one);
	return two;

}

int main() {
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	move_vectors(two, one);

	for (const auto i : two) {
		std::cout << i << " ";
	}
	std::cout << "\n";

	return 0;
}