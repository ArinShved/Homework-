#include <iostream>

#define MODE 1

#if !defined(MODE)
#error "Ошибка! Определите MODE";
#endif;

#if MODE == 1
int add(int a, int b) {
	return a + b;
}
#endif;


int main() {
	setlocale(LC_ALL, "rus");

#if MODE == 1
	std::cout << "Работаю в боевом режиме. " << "\n" << "Введите первое число: ";
	int a, b;
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	std::cout << "Результат сложения: ";
	std::cout << add(a, b);

#elif MODE == 0
	std::cout << "Работаю в режиме тренировки ";

#else 
	setlocale(LC_ALL, "rus");
	std::cout << "Неизвестный режим. Завершение работы";

}
#endif; 
    return 0;
}