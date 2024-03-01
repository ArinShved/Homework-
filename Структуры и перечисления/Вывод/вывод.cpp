// вывод.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>

struct Adress 
{
    std::string city;
    std::string street;
    int num_of_house;
    int num_of_flat;
    int index;

};

void printAdress(struct Adress& adress)
{
    std::cout << "Город: " << adress.city<< "\n";
    std::cout << "Улица: " << adress.street << "\n";
    std::cout << "Дом: " << adress.num_of_house << "\n";
    std::cout << "Квартира: " << adress.num_of_flat << "\n";
    std::cout << "Индекс: " << adress.index << "\n";

}

int main()
{
    setlocale(LC_ALL, "rus");
    Adress adress = {"Москва", "Веселая ",7 , 56 , 987654};
    
    printAdress(adress);


    return 0;
}
