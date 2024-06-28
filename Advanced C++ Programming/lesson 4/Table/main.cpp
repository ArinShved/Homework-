#include <iostream>
#include <vector>

template <class T>
class table {
private:
	std::vector<std::vector<T>> arr;
	int row, column;
public:
	table(int row, int column) {
		this->row = row;
		this->column = column;
		arr.resize(row);
		for (int i = 0; i < row; i++) {
			arr[i].resize(column);
		}
	}

	const std::vector<int> table_size() {
		return { row, column };
	}

	std::vector<T>& operator[](T num) {
		return arr[num];
	}

	const std::vector<T>& operator[](T num) const {
		return arr[num];
	}

};


int main() {

	auto test = table<int>(2, 3);
	test[0][0] = 5;
	std::cout << test[0][0] << "\n";

	return 0;
}