#include "function.h"

int countLargerNum(std::vector<int> arr, int start_point) {
	int left = 0;
	int right = arr.size() - 1;
	int i = arr.size();

	if (start_point > arr[i - 1]) {
		return 0;
	}

	while (left <= right) {
		int middle = (left + right) / 2;
		if (start_point < arr[middle] ) {
			right = middle - 1;
			i = middle;
		}
		else {
			left = middle + 1;
		}
		
	}
	
	return  arr.size() - i;
}