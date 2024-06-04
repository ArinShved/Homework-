
#include <iostream>
#include <fstream>
#include <vector>

void depth_t(std::vector<std::vector<int>> graph, std::vector<int>& visited, int j, int size) {
	visited[j] = 1;
	for (int i = 0; i < size; i++) {
		if (graph[j][i] == 1) {
			if (visited[i] == 0) {
				std::cout << " " << i + 1;
				depth_t(graph, visited, i, size);
			}
		}
	}
}


void depth_f_t(std::vector <std::vector<int>> graph, int size) {
	std::vector<int> visited(size);
	visited[0] = 1;
	for (int i = 1; i < size; i++) {
		visited[i] = 0;
	}

	int i = 0;
	std::cout << "Порядок обхода вершин: " << i + 1 << " ";
	for (int j = 0; j < size; j++) {
		if(graph[i][j] == 1) {
				std::cout << j + 1;
				depth_t(graph, visited, j, size);
				break;
		}
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	int size;

	std::ifstream file("graph.txt");
	if (file.is_open()) {
		file >> size;
		
		std::vector<std::vector<int>> graph(size + 1, std::vector<int>(size + 1));
		
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				file >> graph[i][j];
			}
		}
		depth_f_t(graph, size);
	}
	else {
		std::cout << "Файл не найден!";
		return 0;
	}
	file.close();

	return 0;
}
