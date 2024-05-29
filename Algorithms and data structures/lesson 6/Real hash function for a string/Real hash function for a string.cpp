
#include <iostream>
#include <string>
#include <cmath>

long long real_string_hash(std::string str, int p, int n) {
    long long sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += str[i] * pow(p, i);
    }
    return sum % abs(n);
}

bool s_num(int p) {
    for (int i = 2; i < p; i++) {
        if (p % i == 0) {
            std::cout << "Не является простым числом!\n";
            return 1;
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int p, n;
    std::string user_str;
    bool exit = true;

    while (exit) {
        std::cout << "Введите p: ";
        std::cin >> p;
        exit = s_num(p);
    }

    std::cout << "Введите n: ";
    std::cin >> n;

    exit = true;

    do {
        std::cout << "Введите строку: ";
        std::cin >> user_str;
        std::cout << "Хэш строки " << user_str << " = " << real_string_hash(user_str, p, n) << "\n";
        if (user_str == "exit") {
            break;
        }
    } while (exit);


    system("pause");
    return 0;
}

