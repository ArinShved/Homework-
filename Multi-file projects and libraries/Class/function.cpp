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
    case '�':
    {
        std::cout << "�� ��������! ";
        break;

    }
    default:
    {
        std::cout << "������ " << "\n";
        break;

    }
    }
}