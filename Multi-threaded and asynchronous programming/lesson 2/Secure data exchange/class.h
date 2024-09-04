#pragma once
#include <mutex>


class Data {
private:
	int number;
public:
	mutable std::mutex mtx;

	Data(int num);
	int get_number() const;

	void set_value(int value);
};
