#include <iostream>
#include <fstream>
#include <vector>



void dfs(std::vector<std::vector<int>> arr, int i, std::vector<bool>& visited, std::vector<int>& order, int size){
	visited[i] = true;
	for (int j = 0; j < size; j++) {
		if (arr[i][j] == 1) {
			if (!visited[j]) {
				dfs(arr, j, visited, order, size);
			}
		}
	}

	order.insert(order.begin(), i);
}

std::vector<int> sort_graph(std::vector<std::vector<int>> arr, int size) {

	std::vector<int> order;
	std::vector<bool> visited(size, 0);
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (!visited[i]) {
			dfs(arr, i, visited, order, size);
		}
	}
	

	return order;
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
		
		
		std::vector<int> arr_1 = sort_graph(arr, size);
		std::cout << "Топологический порядок вершин: ";
		for (int i = 0; i < size; i++) {
			std::cout << arr_1[i] + 1 << " ";
		}
	}
	else {
		std::cout << "Ошибка файла";
		return 0;
	}

	system("pause");
	return 0;
}