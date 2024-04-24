

#include <iostream>

int fibbonachi(int i) {
    if (i == 0) {
        return 0;
    }
    else if (i == 1) {
        return 1;
    }
    else {
        return fibbonachi(i - 2) + fibbonachi(i - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    while (true) {
        int i;
        std::cout << "Введите число: ";
        std::cin >> i;
      
        std::cout << "Число Фибоначчи: " << fibbonachi(i) << "\n";
    }

    system("pause");
    return 0;

}

