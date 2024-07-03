
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

bool comparison(std::pair<char, int>& a, std::pair<char, int>& b){ 
	return a.second > b.second;
}

void sort_map(std::map<char, int>& frequency) {
	std::vector<std::pair<char, int>> sort_arr;
	for (auto& i : frequency) {
		sort_arr.push_back(i);
	}

	std::sort(sort_arr.begin(), sort_arr.end(), comparison);

	for (auto& i : sort_arr) {
		std::cout << i.first << ": " << i.second << "\n";
	}
}

void count_char(char* text, int length){
	std::map<char, int> frequency;
	for (int i = 0; i < length; i++) {
		char current_char = text[i];
		if (frequency.find(current_char) != frequency.end()) {
			frequency[current_char]++;
		}
		else {
			frequency[current_char] = 1;
		}
	}
	sort_map(frequency);
}



int main()
{
	char text[] = "Hello world!!";
	int length = sizeof(text) / sizeof(text[0]) - 1;
	std::cout << "[In]: " << text << "\n" << "[Out]" << "\n";
	count_char(text, length);

	return 0;
}
