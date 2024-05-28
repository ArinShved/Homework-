#include <iostream>
#include <vector>
#include <string>

#include "functions.h"

int main()
{
    setlocale(LC_ALL, "rus");
    std::vector<int> arr = { 1, 3, 6, 5, 9, 8};
   
    bool exit = true;
    int a = 0;
    std::string user_answer;
 
    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr.size(); i++) {

        std::cout << arr[i] << " ";
    }

    std::cout << "\nПирамида:  ";
    print_pyramid(arr);

    do {
        std::cout << "\nВы находитесь здесь:";
        print_index(arr, a);

        std::cout << "\nВведите команду: ";
        std::cin >> user_answer;
   
        if(user_answer == "right"){
            a = child_right(arr, a);
        }
        else if(user_answer == "left"){
            a = child_left(arr, a);
        }
        else if (user_answer == "up") {
            int temp = a;
            a = parent_index(a);
            if (temp != a) {
                std::cout << "\nOk\n";
            }
        
        }
        else if (user_answer == "exit") {
            break;
        }
        else {
            std::cout << "\nНеверная команда!\n";
            continue;
        }
       
    } while (exit);


    system("pause");
    return 0;
}
