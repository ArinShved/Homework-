#include <iostream>
#include <vector>

class counter {
private:
	int sum;
	int count;
public:
	counter() {
		sum = 0;
		count = 0;
	}

	const int get_sum() {
		return sum;
	}

	const int get_count() {
		return count;
	}

	void operator()(std::vector<int> arr) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] % 3 == 0) {
				sum += arr[i];
				count++;
			}
		}
	}
};

int main() {
	
	std::vector<int> arr = { 4, 1, 3, 6, 25, 54 };
	counter counter;
	counter(arr);

	std::cout << "[In]: ";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	
	std::cout << "\n[Out]: get_sum() = " << counter.get_sum() 
		<< "\n[Out]: get_count() = " << counter.get_count();

	return 0;
}