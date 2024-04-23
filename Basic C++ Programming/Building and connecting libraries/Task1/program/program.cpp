#include <iostream>
#include <Windows.h>
#include "Greeter.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите имя: ";
    std::string name;
    std::cin >> name;
    Greeter greeting(name);
    greeting.greet(name);


    system("pause");
    return 0;
}

