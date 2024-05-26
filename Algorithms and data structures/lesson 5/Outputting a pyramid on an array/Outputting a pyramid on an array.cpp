
#include <iostream>
#include <vector>


void print_pyramid(std::vector<int> arr) {
    int arr_size = arr.size();
    std::cout << "\n" << 0 << " root " << arr[0] << "\n";

    for (int i = 0; i < arr_size; i++)
    {
        
        if (2 * i +1 < arr.size()) {
            int j = abs(i / 2 - 1);
            std::cout << j << " left(" << arr[i] << ") " << arr[2 * i + 1] << "\n";
        }
        if (2 * i + 2 < arr.size()) {
            int j = abs(i / 2 - 2);
            std::cout << j << " right(" << arr[i] << ") " << arr[2 * i + 2] << "\n";
        }

        arr_size -= i * 2;

    }
}



int main()
{
    setlocale(LC_ALL, "rus");
    std::vector<int> arr = { 1,3, 6, 5, 9, 8 };
    std::vector<int> arr_1 = { 94, 67, 18, 44, 55, 12, 6, 42 };
    std::vector<int> arr_2 = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr.size(); i++) {
        
        std::cout << arr[i] << " ";
    }
    print_pyramid(arr);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr_1.size(); i++) {

        std::cout << arr_1[i] << " ";
    }
    print_pyramid(arr_1);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr_2.size(); i++) {

        std::cout << arr_2[i] << " ";
    }
    print_pyramid(arr_2);

    system("pause");
    return 0;
}
