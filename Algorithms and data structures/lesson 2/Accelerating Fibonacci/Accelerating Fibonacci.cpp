
#include <iostream>
#include <vector>


int fibbonachi(int i, std::vector<int>& memory) {
    if (memory[i] != -1) {
        return memory[i];
    }
     if (i == 1||i == 0) {
        return i;
    }
     memory[i] = fibbonachi(i - 2, memory) + fibbonachi(i - 1, memory);
     return memory[i];
}

int main()
{
    setlocale(LC_ALL, "rus");
    while (true) {
        int i;
        std::cout << "Введите число: ";
        std::cin >> i;
        std::vector<int> memory(i + 1, -1);

        std::cout << "Число Фибоначчи: " << fibbonachi(i, memory) << "\n";
    }

    system("pause");
    return 0;

}