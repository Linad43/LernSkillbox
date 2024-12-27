#include "..\HeaderModul4.h"

void mod4ex5() {
	std::cout << "5. Кратность числа\n";

	int a, b;
	std::cout << "Введите первое число:" << std::endl;
	std::cin >> a;
	std::cout << "Введите второе число:" << std::endl;
	std::cin >> b;
	if (a % b == 0) {
		std::cout << "Да! Первое число " << a << " делится на второе " << b << " без остатка" << std::endl;
	}
	else {
		std::cout << "Нет! Первое число " << a << " не делится на второе " << b << " без остатка" << std::endl;
	}
}