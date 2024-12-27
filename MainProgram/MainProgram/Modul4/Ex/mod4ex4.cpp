#include "..\HeaderModul4.h"

void mod4ex4() {
	std::cout << "4. Калькулятор опыта\n";

	double exp;
	std::cout << "Введите число очков опыта: " << std::endl;
	std::cin >> exp;
	if (exp < 0) {
		std::cout << "Ошибка ввода, опыт не может быть отрицательным!" << std::endl;
	}
	else if (exp >= 0 && exp < 1000) {
		std::cout << "Ваш уровень: 1" << std::endl;
	}
	else if (exp >= 1000 && exp < 2500) {
		std::cout << "Ваш уровень: 2" << std::endl;
	}
	else if (exp >= 2500 && exp < 5000) {
		std::cout << "Ваш уровень: 3" << std::endl;
	}
	else {
		std::cout << "Ваш уровень: 4" << std::endl;
	}
}