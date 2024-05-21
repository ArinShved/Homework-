

#include <iostream>

#include "function.h"

int main() {
    setlocale(LC_ALL, "rus");

    int actual_size, logical_size;
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;

    int* arr = new int[actual_size];

    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;
    if (logical_size > actual_size) {
        std::cout << "Неправильный логический размер.\n ";
        return 0;
    }

    for (int i = 0; i < logical_size; i++) {
        std::cout << "Введите а[" << i << "]\n";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);


    int user_answer = 1;
    do {
        std::cout << "Введите новый элемент: ";
        int new_i;
        std::cin >> new_i;

        arr = append_to_dynamic_array(arr, logical_size, actual_size, new_i);
        print_dynamic_array(arr, logical_size, actual_size);

        std::cout << "Для продолжения ввода эллементов нажмите 1. Для выхода - 0. ";
        std::cin >> user_answer;
    } while (user_answer != 0);

    std::cout << "Спасибо! ";
    print_dynamic_array(arr, logical_size, actual_size);
    delete[]arr;

    system("pause");
    return 0;
}