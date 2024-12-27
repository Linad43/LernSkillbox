#include "..\HeaderModul5.h"

void mod5ex2() {
	std::cout << "2. Майские!" << std::endl;
	std::cout << "Введите номер дня" << std::endl;

	int day;
	std::cin >> day;
	if (day > 0 && day <= 31) {
		if (day % 7 == 6 || day % 7 == 0 || (day >= 1 && day <= 5) || (day >= 8 && day <= 10)) {
			std::cout << "Введен выходной" << std::endl;
		}
		else {
			std::cout << "Введен рабочий" << std::endl;
		}
	}
	else {
		std::cout << "Ошибка ввода" << std::endl;
	}
}