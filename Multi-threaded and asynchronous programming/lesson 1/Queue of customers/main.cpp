#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

const int max_clients = 20;

void client(int& num) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	do {
		num++;

		std::cout << " Прибыл клиент\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	} while (num < max_clients);
}

void queue_operator(int& num) {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	
	do {
		num--;
		std::cout << " Клиент ушел\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
	} while (num > 0);
}


int main() {
	setlocale(LC_ALL, "rus");

	std::cout << "Начало очереди \n";
	
	int num_of_client = 10;
	
	std::thread th1(client, std::ref(num_of_client));
	std::thread th2(queue_operator, std::ref(num_of_client));

	th1.join();
	th2.join();

	std::cout << "Конец очереди\n";

	return 0;
}