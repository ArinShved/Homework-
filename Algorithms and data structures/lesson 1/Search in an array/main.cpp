#include <vector>
#include <iostream>

#include "function.h"

int main()
{
    setlocale(LC_ALL, "rus");
    do {
        int start_point;
        std::vector<int> arr = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
        std::cout << "Введите точку отсчёта:  ";
        std::cin >> start_point;

        std::cout << "Количество элементов в массиве больших, чем " << start_point << ": " << countLargerNum(arr, start_point) << "\n";
    } while (true);
    return 0;
}

