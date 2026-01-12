#include "header_modul6.h"

void mod6ex7() {
	std::cout << "7. Сокращение дроби" << std::endl;
	int num, denom;
	std::cout << "Введите числитель: ";
	std::cin >> num;
	std::cout << "Введите знаменатель: ";
	std::cin >> denom;
	if (denom == 0) {
		std::cout << "Деление на ноль невозможно\n";
		return;
	}
	else if (num == 0) {
		std::cout << "Результат: 0\n";
		return;
	}
	else if (num * denom < 0) {
		num = -abs(num);
		denom = abs(denom);
	}
	else if (num < 0) {
		num = abs(num);
		denom = abs(denom);
	}
	std::cout << "Результат: " << num / nod(num, denom) << " / " << denom / nod(num, denom) << std::endl;
}
