#include "header_modul12.h"
#define SIZE_NAMES 10

void mod12ex1() {
	std::cout << "1. Многоквартирный дом.\n";
	std::string names[SIZE_NAMES];
	int choice = 1;
	for (int i = 0; i < SIZE_NAMES; i++) {
		std::cin >> names[i];
	}
	while (choice != 0) {
		std::cout << "Введите номер квартиры или \"0\" для выхода\n";
		std::cin >> choice;
		if (choice > 0 && choice <= SIZE_NAMES) {
			std::cout << names[choice - 1] << std::endl;
		}
		else if (choice != 0) {
			std::cout << "Некорректный ввод\n";
		}
	}
}