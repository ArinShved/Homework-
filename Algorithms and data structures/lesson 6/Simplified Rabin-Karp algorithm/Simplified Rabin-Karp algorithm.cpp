

#include <iostream>
#include <string>

int hash(std::string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += str[i];
    }
    return sum;
}

int ind_substring_light_rabin_karp(std::string str, std::string sub_str) {
    int sub_str_hash = hash(sub_str);
    int k = sub_str.size();
    int h = 0;
    for (int i = 0; i < str.size(); i++) {
        if (i + k - 1 > str.size()) {
            break;
        }

        if (i == 0) {
            std::string str_1 = str.substr(0, k);
            h = hash(str_1);
        }
        else {
            h -= str[i - 1];
            h += str[i + (k - 1)];

        }

        if (h != sub_str_hash) {
            continue;
        }
        else {
            for (int j = 0; j < k; j++) {
                if (str[i + j] != sub_str[j]) {
                    break;
                }
                else {
                    return i;
                }
            }
        }
    }

    return -1;
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::string str, sub_str;
    bool exit = true;

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str;

    do {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> sub_str;
       
       int i = ind_substring_light_rabin_karp(str, sub_str);
       if (i < 0) {
           std::cout << "Подстрока " << sub_str << " не найдена\n";
       }
       else {
           std::cout << "Подстрока " << sub_str << " имеет индекс " << i << "\n";
       }

       if (sub_str == "exit") {
           break;
       }
    } while (exit);


    system("pause");
    return 0;
    
}
