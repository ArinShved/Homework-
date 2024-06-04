
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


void wide_t(std::vector <std::vector<int>> graph, int size, int num) {
	std::vector<int> visited(size);
	for (int i = 0; i < size; i++) {
		visited[i] = 0;
	}
	std::cout << "Порядок обхода вершин: " << " ";

	visited[num-1] = 1;
	std::queue<int> queue;
	queue.push(num-1);
	

	for (int j = 0; j < size; j++) {
		if (graph[num-1][j] == 1) {
			if (visited[j] == 0) {
				queue.push(j);
				visited[j] = 1;
			}
		}
	}

	while (!queue.empty()) {
		int i = queue.front();
		visited[i] = 1;
		queue.pop();
		std::cout << i + 1 << " ";
		for (int j = 0; j < size; j++) {
			if (visited[j] == 0) {
				if (graph[i][j] == 1) {
					queue.push(j);
					visited[j] = 1;
				}
			}
		}
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	int user_num;

	std::ifstream file("graph.txt");
	if (file.is_open()) {
		file >> size;

		std::vector<std::vector<int>> graph(size + 1, std::vector<int>(size + 1));

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				file >> graph[i][j];
			}
		}
		

		std::cout << "В графе " << size <<  " вершин. Введите номер вершины, с которой начнётся обход : ";
		do {
			std::cin >> user_num;
			if (user_num > 0 && user_num <= size) {
				break;
			}
			else {
				std::cout << "Неверное число! Повторите попытку!\n";
			}
		} while (true);

		wide_t(graph, size, user_num);
	}
	else {
		std::cout << "Файл не найден!";
		return 0;
	}
	file.close();

	return 0;
}
