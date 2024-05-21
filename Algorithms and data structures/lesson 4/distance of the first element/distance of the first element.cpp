#include <iostream>
#include <Windows.h>
#include <string>
#include "function.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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

    std::string user_answer;

    do {
        std::cout << "Хотите удалить первый элемент массива? Введите 'да' или 'нет'    ";
        std::cin >> user_answer;

        if (user_answer == "да" || user_answer == "Да") {
            if (logical_size > 0) {
                arr = remove_dynamic_array_head(arr, logical_size, actual_size);
                print_dynamic_array(arr, logical_size, actual_size);
            }
            else {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!\n";
                break;
            }
        }
        else {
            std::cout << "Спасибо! ";
            print_dynamic_array(arr, logical_size, actual_size);
            
            break;
        }
    } while (user_answer == "да" || user_answer == "Да");

    delete[]arr;
    system("pause");
    return 0;
}