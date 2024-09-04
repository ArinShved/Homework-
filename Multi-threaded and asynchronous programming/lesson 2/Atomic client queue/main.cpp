#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>


class Queue {
private:
	const int max_clients = 5;
	std::atomic<int> num_of_client{1};
	int client_num_mtx = 1;
	std::mutex mtx;

public:
	Queue(){};

	void client() {
		do {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			num_of_client.fetch_add(1);
			std::cout << " Прибыл клиент\n";

		} while (num_of_client.load() < max_clients);
	}

	void queue_operator() {
		do {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			num_of_client.fetch_sub(1);
			std::cout << " Клиент ушел\n";
		} while (num_of_client.load() > 0);
	}

	void op_with_mtx() {
		do {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			{
				std::lock_guard<std::mutex> lock(mtx);
				client_num_mtx--;
			}
			std::cout << " Клиент ушел\n";
			
		} while (client_num_mtx > 0);
	}
	void client_with_mtx() {
		do {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			{
				std::lock_guard<std::mutex> lock(mtx);
				client_num_mtx++;
			}
			std::cout << " Прибыл клиент\n";
			
		} while (client_num_mtx < max_clients);
	}

};

int main() {
	setlocale(LC_ALL, "rus");

	std::cout << "Начало работы\n";

	Queue m;
	auto start = std::chrono::steady_clock::now();
	std::thread th1([&]()
		{m.client();
		});
	std::thread th2([&]() {
		m.queue_operator();
		});

	th1.join();
	th2.join();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> time = end - start;
	std::cout << "Конец работы, используя atomic. Время работы: " << time.count() << "\n";

	auto start_mtx = std::chrono::steady_clock::now();
	std::thread th3([&]()
		{m.client_with_mtx();
		});
	std::thread th4([&]() {
		m.op_with_mtx();
		});

	th3.join();
	th4.join();
	auto end_mtx = std::chrono::steady_clock::now();
	std::chrono::duration<double> time_mtx = end_mtx - start_mtx;
	std::cout << "Конец работы, используя mutex. Время работы: \n" << time_mtx.count();


	return 0;
}