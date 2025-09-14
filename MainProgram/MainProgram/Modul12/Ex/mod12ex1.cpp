#include "..\header_modul12.h"
#define SIZE_NAMES 10

void mod12ex1() {
	std::cout << "1. Многоквартирный дом.\n";
	std::string names[SIZE_NAMES];
	int choise = 1;
	for (int i = 0; i < SIZE_NAMES; i++) {
		std::cin >> names[i];
	}
	while (choise != 0) {
		std::cout << "Введите номер квартиры или \"0\" для выхода\n";
		std::cin >> choise;
		if (choise > 0 && choise <= SIZE_NAMES) {
			std::cout << names[choise - 1] << std::endl;
		}
		else if (choise != 0) {
			std::cout << "Некорректный ввод\n";
		}
	}
}