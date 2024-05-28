#include "functions.h"


void print_pyramid(std::vector<int> arr) {
    int arr_size = arr.size();
    std::cout << "\n" << 0 << " root " << arr[0] << "\n";
    int j = 1;

    for (int i = 0; i < arr_size; i++)
    {

        if (2 * i + 1 < arr.size()) {
            std::cout << j << " left(" << arr[i] << ") " << arr[2 * i + 1] << "\n";
        }
        if (2 * i + 2 < arr.size()) {
            std::cout << j << " right(" << arr[i] << ") " << arr[2 * i + 2] << "\n";
        }

        if (i % 2 == 0) {
            j++;
        }

    }
}

int parent_index(int a) {
    double new_a = (a - 1) / 2;
    if (new_a < 0 || a == 0) {
        std::cout << "\nОшибка! Отсутствует родитель\n";
        return a;
    }
    else {
        return ((a - 1) / 2);
    }

}

void print_index(std::vector<int> arr, int a) {
    if (a == 0) {
        std::cout << "\n" << 0 << " root " << arr[0] << " \n";
    }
    else if (a % 2 == 0) {
        int j = parent_index(a);
        std::cout << "\n " << round(sqrt(a)) << " right(" << arr[j] << ") " << arr[a] << "\n";
    }
    else if (a % 2 == 1) {
        int j = parent_index(a);
        std::cout << "\n" << round(sqrt(a)) << " left(" << arr[j] << ") " << arr[a] << "\n";
    }

}


int child_left(std::vector<int> arr, int a) {
    if (a * 2 + 1 < arr.size()) {
        std::cout << "\nOk\n";
        return a * 2 + 1;
    }
    else {
        std::cout << "\nОшибка! Отсутствует левый потомок\n ";
        return a;
    }
}

int child_right(std::vector<int> arr, int a) {
    if (a * 2 + 2 < arr.size()) {
        std::cout << "\nOk\n";
        return a * 2 + 2;
    }
    else {
        std::cout << "\nОшибка! Отсутствует правый потомок\n ";
        return a;
    }
}
