
#include <iostream>

#define MODE 1

#if !defined(MODE)
#error "Ошибка! Определите MODE";
#endif;

#if MODE == 1
int add(int a, int b) {
	return a + b;
}

int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "Работаю в боевом режиме. " << "\n" << "Введите первое число: ";
	int a, b;
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	std::cout << "Результат сложения: ";

	std::cout << add(a, b);
	return 0;
}
#elif MODE == 0
int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "Работаю в режиме тренировки ";
	return 0;
}
#else 
int main(){
	setlocale(LC_ALL, "rus");
	std::cout << "Неизвестный режим. Завершение работы";
	return 0;
}
#endif; 


