
#include <iostream>
#include <string>
#include <Windows.h>

struct account
{
    int num = 0;
    std::string name;
    double balance = 0;
};

void changeBalance(account& user, double new_balance)
{
    user.balance = new_balance;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    account user;
    double new_balance = 0;
    std::cout << "Введите номер счёта: ";
    std::cin >> user.num;
    std::cout << "Введите имя владельца: ";
    std::cin >> user.name;
    std::cout << "Введите баланс: ";
    std::cin >> user.balance;
    std::cout << "Введите новый баланс: ";
    std::cin >> new_balance;
    changeBalance(user, new_balance);
    std::cout << "Ваш счет: " << user.name << ", " << user.num << ", " << user.balance << "\n";


    return 0;
}