#include "header_modul6.h"

void mod6ex1() {
	std::cout << "1. Кукушка" << std::endl;
	int hour;
	while (1) {
		std::cout << "Введите, который час: ";
		std::cin >> hour;
		if (hour > 0 && hour <= 24) {
			break;
		}
		else {
			std::cout << "Неверно введенные данные!\nВведенное значение должно быть в диапазоне (0;24]\n";
		}
	}
	int i = 0;
	while (++i <= hour) {
		std::cout << "Ку-ку\n";
	}
}