
#include <iostream>
#include <string>
#include <windows.h>


class Counter
{
private:
    int num;
public: 
    int increaseCounter()
    {
        return num++;
    };
    int reduceCounter()
    {
        return num--;
    };
    void showCounter()
    {
        std::cout << num << "\n";
    };
    Counter()
    {
        num = 1;
    };
    Counter(int num)
    {
        this->num = num;
    }
};

void coosingCommand(Counter& counter, char users_response)
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
        std::cout << "До свидания! ";
        break;

    }
    default:
    {
        std::cout << "Ошибка " << "\n";
        break;

    }
    }
}

int main()
{ 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //setlocale(LC_ALL, "RUS");

    char users_response;
    std::string answer;
    int num = 0;

    std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";
    getline(std::cin, answer);
    
    if (answer == "да" || answer == "Да" || answer == "ДА")
    {
        std::cout << "Введите начальное значение счетчика: ";
        std::cin >> num;

        Counter counter(num);

        do {
            std::cout << "Введите команду('+', '-', '=' или 'x'): ";
            std::cin >> users_response;
            coosingCommand(counter, users_response);
            if (users_response == 'х' || users_response == 'Х')
            {
                break;
            }
        } while (true);
    }
    else
    {
        Counter counter;
        do {
            std::cout << "Введите команду('+', '-', '=' или 'x'): ";
            std::cin >> users_response;
            coosingCommand(counter, users_response);
            if (users_response == 'х' || users_response == 'Х')
            {
                break;
            }
        } while (true);

    }

  return 0;
        
   }
