#include "..\header_modul4.h"

void mod4ex2() {
	std::cout << "2. Складываем в уме" << std::endl;
	double a, b, sum;
	std::cout << "Введите первое число:" << std::endl;
	std::cin >> a;
	std::cout << "Введите второе число:" << std::endl;
	std::cin >> b;
	std::cout << "Введите их сумму:" << std::endl;
	std::cin >> sum;
	if (sum == a + b) {
		std::cout << "Верно!" << std::endl;
	}
	else {
		std::cout << "Ошибка, верный результат: " << a + b << std::endl;
	}
}