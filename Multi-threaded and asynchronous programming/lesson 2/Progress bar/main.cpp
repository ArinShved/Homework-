#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <Windows.h>

std::mutex mtx;

void go_to_xy(int x, int y)
{
	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
}

void simulateCalculation(int threadNumber, int Y) {
	
	int progress = 20;
	int duration = 1500;

	auto start = std::chrono::steady_clock::now();
	{
		std::lock_guard<std::mutex> lock(mtx);
		go_to_xy(0, Y);
		std::cout << threadNumber << "  " << std::this_thread::get_id();
		go_to_xy(9, Y);
		std::cout << "[";
	}

	for (int i = 10; i <= progress + 9; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(duration / progress));
		{
			std::lock_guard<std::mutex> lock(mtx);
			go_to_xy(i, Y);
			std::cout << "#";
			std::this_thread::sleep_for(std::chrono::milliseconds(duration / progress));
		}
	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> time = end - start;

	{
		std::lock_guard<std::mutex> lock(mtx);
		go_to_xy(30, Y);
		std::cout << "]  " << time.count() << "c  ";
	}
	
	go_to_xy(0, 10);
} 


int main() {
	
	int thread_num = 6;
	std::vector<std::thread> thread_arr(thread_num);

	for (int i = 0; i < thread_num; i++) {
		thread_arr[i] = std::thread(simulateCalculation, i + 1, i);
	}

	for (auto& th : thread_arr) {
		th.join();
	}

	return 0;
}