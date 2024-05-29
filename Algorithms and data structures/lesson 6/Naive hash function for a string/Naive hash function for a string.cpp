
#include <iostream>
#include <string>

int simple_string_hash(std::string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += str[i];
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::string user_str;

    do {
        std::cout << "Введите строку: ";
        std::cin >> user_str;
        std::cout << "Наивный хэш строки " << user_str << " = " << simple_string_hash(user_str) << "\n";
        if (user_str == "exit") {
            break;
        }
    } while (exit);

    system("pause");
    return 0;
}
