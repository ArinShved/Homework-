// месяцы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <vector>
#include <string>

enum mounth
{
    stop,
    junuary,
    february,
    march,
    april ,
    may,
    june,
    july,
    august,
    september,
    october ,
    november,
    december
};

void printMounth(mounth& mounth, std::vector<std::string> name_of_mounths, int num)
{
    switch (num)
    {
    case junuary:
    {  std::cout << name_of_mounths[junuary] << "\n";
    break;
    }
    case february:
    {
        std::cout << name_of_mounths[february] << "\n";
        break;
    }
    case march:
    {
        std::cout << name_of_mounths[march] << "\n";
        break;
    }
    case april:
    {
        std::cout << name_of_mounths[april] << "\n";
        break;
    }
    case may:
    {
        std::cout << name_of_mounths[may] << "\n";
        break;
    }
    case june:
    {
        std::cout << name_of_mounths[june] << "\n";
        break;
    }
    case july:
    {
        std::cout << name_of_mounths[july] << "\n";
        break;
    }
    case august:
    {
        std::cout << name_of_mounths[august] << "\n";
        break;
    }
    case september:
    {
        std::cout << name_of_mounths[september] << "\n";
        break;
    }
    case october:
    {
        std::cout << name_of_mounths[october] << "\n";
        break;
    }
    case november:
    {
        std::cout << name_of_mounths[november] << "\n";
        break;
    }
    case december:
    {
        std::cout << name_of_mounths[december] << "\n";
        break;
    }
    default:
    {
        std::cout << name_of_mounths[name_of_mounths.size() - 1] << "\n";
        break;
    }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::vector<std::string> name_of_mounths = { "До свидания ", "январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь", "Неправильный номер!"};
    mounth m;
    
    int num = 1;
    while (num != 0) {
        std::cout << "Введите номер месяца: ";
        std::cin >> num;
        if (num == stop)
        {
            std::cout << name_of_mounths[stop] << "\n";
            break;
        }
        printMounth(m, name_of_mounths, num);
    }

    return 0;
}

