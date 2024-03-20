
#include <iostream>

class Calculator
{
public:
    double num1 = 0;
    double num2 = 0;

    Calculator(double num1, double num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    };

    double add()
    {
        return num1 + num2;
    };
    double multiply()
    {
        return num1 * num2;
    };
    double subtract_1_2()
    {
        return num1 - num2;
    };
    double subtract_2_1()
    {
        return num2 - num1;
    };
    double divide_1_2()
    {
        return num1 / num2;
    };
    double divide_2_1()
    {
        return num2 / num1;
    };
    bool set_num1(double num1)
    {
        if (num1 != 0) {
            this->num1 = num1;
            if (this->num1 == num1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            std::cout << "Неверный ввод!" << "\n";
            return false;
        }
    };
    bool set_num2(double num2)
    {
        if (num2 != 0) {
            this->num2 = num2;
            if (this->num2 == num2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else {
            std::cout << "Неверный ввод!" << "\n";
            return false;
        }
    };
};

int main()
{
    setlocale(LC_ALL, "rus");
    do {
        double num1, num2;
        std::cout << "Введите num1: ";
        std::cin >> num1;
        std::cout << "Введите num2: ";
        std::cin >> num2;

        Calculator calculator(num1, num2);
       
        if (calculator.set_num1(num1) == 1 && calculator.set_num2(num2) == 1)
        {
            std::cout << "num1 + num2 = " << calculator.add() << "\n";
            std::cout << "num1 - num2 = " << calculator.subtract_1_2() << "\n";
            std::cout << "num2 - num1 = " << calculator.subtract_2_1() << "\n";
            std::cout << "num1 * num2 = " << calculator.multiply() << "\n";
            std::cout << "num1 / num2 = " << calculator.divide_1_2() << "\n";
            std::cout << "num2 / num1 = " << calculator.divide_2_1() << "\n";

        }
        else
            continue;
    } while (true);
    
    return 0;
}
