#include <iostream>
#include "header.h"


void choosingCommand(Counter& counter, char users_response)
{
    switch (users_response)
    {
    case '+':
    {
        counter.increaseCounter();
        break;
    }
    case '-':
    {
        counter.reduceCounter();
        break;
    }
    case '=':
    {
        counter.showCounter();
        break;
    }
    case 'х':
    {
        std::cout << "До свидания!";
        break;

    }
    default:
    {
        std::cout << "Ошибка!" << "\n";
        break;

    }
    }
}