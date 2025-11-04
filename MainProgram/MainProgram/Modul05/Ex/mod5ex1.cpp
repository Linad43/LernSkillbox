#include "..\header_modul5.h"

void mod5ex1() {
	std::cout << "1. Полет нормальный" << std::endl;
	int speed, height;
	std::cout << "Введите скорость полета" << std::endl;
	std::cin >> speed;
	std::cout << "Введите высоту полета" << std::endl;
	std::cin >> height;
	if (speed >= 750 && speed <= 850 && height >= 9000 && height <= 9500) {
		std::cout << "Полет нормальный" << std::endl;
	}
	else {
		std::cout << "Необходима корректировка полета" << std::endl;
	}
}