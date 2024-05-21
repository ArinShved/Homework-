

#include <iostream>
#include "function.h"

int main()
{
    setlocale(LC_ALL, "rus");
    while (true) {
        int actual_size, logical_size;
        std::cout << "Введите фактичеcкий размер массива: ";
        std::cin >> actual_size;

        int* arr = new int[actual_size];

        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
        if (logical_size > actual_size) {
            std::cout << "Неправильный логический размер.\n ";
            continue;
        }

        for (int i = 0; i < logical_size; i++) {
            std::cout << "Введите а[" << i << "]\n";
            std::cin >> arr[i];
        }

        print_dynamic_array(arr, logical_size, actual_size);
        delete[]arr;
    }

    system("pause");
    return 0;
}
