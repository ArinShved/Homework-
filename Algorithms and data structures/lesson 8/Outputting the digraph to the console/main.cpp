#include <iostream> 
#include <fstream>
#include <vector>

void output_graph(std::vector<std::vector<int>> arr, int size){
	std::cout << "Текстовый вид орграфа:\n";

	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ": ";
		int sum = 0;
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 1) {
				std::cout << j + 1 << " ";
			}
			sum += arr[i][j];
		}
		if (sum == 0) {
			std::cout << "нет ";
		}
		std::cout << "\n";
	}
}



int main() {
	setlocale(LC_ALL, "rus");
	std::ifstream file("out.txt");
	int size;

	if (file.is_open()) {
		file >> size;
		std::vector<std::vector<int>> arr(size, std::vector<int>(size));
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				file >> arr[i][j];
			}
		}
		output_graph(arr, size);
	}
	else {
		std::cout << " ";
		return 0;
	}

	file.close();
	system("pause");
	return 0;
}