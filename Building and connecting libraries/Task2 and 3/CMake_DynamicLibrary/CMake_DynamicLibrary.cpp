﻿
#include "CMake_DynamicLibrary.h"


#include <iostream>
#include <Windows.h>
#include "leaver.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите имя: ";
    std::string name;
    std::cin >> name;
    Leaver leaving(name);
    leaving.leave(name);


    system("pause");
    return 0;
}
