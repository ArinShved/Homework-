#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <exception>



class ini_parser {
private:
	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> section;
public:
	ini_parser(std::string file) {
		
		std::ifstream in(file + ".ini");
		if (!in.is_open()) {
			throw std::runtime_error("Некорректное открытие файла");
		}

		std::string line, current_section;

		while (std::getline(in, line)) {
			std::string key, value;
			if (line.empty()) {
				continue;
			}
			
			for (size_t i = 0; i < line.size(); i++) {
				if (line[i] == ';') {
					line.erase(i);
				}
			}

			if (line[0] == '[') {
				for (size_t i = 0; i < line.size(); i++) {
					if (line[i] == ']') {
						current_section = line.substr(1, i-1);
					}
				}
				for (size_t i = 0; i < current_section.size(); i++) {
					current_section[i] = std::tolower(current_section[i]);
				}
				section[current_section];
				continue;
			}

			for (size_t i = 0; i < line.size(); i++) {
				if (line[i] == '=') {
					key = line.substr(0, i);
					value = line.substr(i + 1);
				}
			}

			for (size_t i = 0; i < key.size(); i++) {
				key[i] = std::tolower(key[i]);
			}

			section[current_section][key] = value;
		}
		in.close();
	}

	template <typename T>
	T get_value(std::string section_and_key) {
		std::string sections, key;

		for (size_t i = 0; i < section_and_key.size(); i++) {
			section_and_key[i] = std::tolower(section_and_key[i]);
		}

		for (size_t i = 0; i < section_and_key.size(); i++) {
			if (section_and_key[i] == '.') {
				sections = section_and_key.substr(0, i);
				key = section_and_key.substr(i + 1);
			}
		}

		auto it = section.find(sections);
		if (it == section.end()) {
			throw std::exception("Секция не найдена");
		}
		auto sub_it = it->second.find(key);
		if (sub_it == it->second.end()) {
			if (it->second.empty()) {
				throw std::exception("Пустая секция");
			}
			else {
				std::cout << "Может, вы имели ввиду:\n";
				for (auto& i : it->second) {
					std::cout << i.first << "\n";
				}
				throw std::exception("Значение не найдено.");
			}
		}
		try {
			return std::stod(sub_it->second);
		}
		catch (...) {
			throw std::exception("Неправильный тип переменной. Может вы имели ввиду std::string?");
		}

	}

	template<>
	std::string get_value(std::string section_and_key) {
		std::string sections, key;

		for (size_t i = 0; i < section_and_key.size(); i++) {
			section_and_key[i] = std::tolower(section_and_key[i]);
		}

		for (size_t i = 0; i < section_and_key.size(); i++) {
			if (section_and_key[i] == '.') {
				sections = section_and_key.substr(0, i);
				key = section_and_key.substr(i + 1);
			}
		}

		auto it = section.find(sections);
		if (it == section.end()) {
			throw std::exception("Секция не найдена");
		}
		auto sub_it = it->second.find(key);
		if (sub_it == it->second.end()) {
			if (it->second.empty()) {
				throw std::exception("Пустая секция");
			}
			else {
				std::cout << "Может, вы имели ввиду:\n";
				for (auto& i : it->second) {
					std::cout << i.first << "\n";
				}
				throw std::exception("Значение не найдено.");
			}
		}

		return (sub_it->second);
	}
	
};



int main() {
	setlocale(LC_ALL, "rus");

	try {
		ini_parser parser("file");
		auto value = parser.get_value<int>("Section1.var1");
		std::cout << value << "\n";
		auto value_1 = parser.get_value<std::string>("Section4.var");
		std::cout << value_1 << "\n";
		
	}
	catch (const std::exception& e) {
		std::cerr << "Ошибка! "<< e.what() << "\n";
	}

	return 0;

}