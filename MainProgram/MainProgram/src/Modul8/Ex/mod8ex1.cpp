#include "header_modul8.h"

void mod8ex1() {
	std::cout << "1. Космический симулятор\n";
	float f = 0, m = 0, t = 0;

	/*
	std::cout << "Введите массу звездолета: ";
	while (1) {
		std::cin >> m;
		if (m <= 0) {
			std::cout << "Масса звездолета должна быть больше нуля!\n";
			std::cout << "Повторите ввод: ";
			continue;
		}
		else {
			break;
		}
	}

	std::cout << "Введите силу тяги: ";
	while (1) {
		std::cin >> f;
		if (f < 0) {
			std::cout << "Сила тяги не может быть отрицательным значением\n";
			std::cout << "Повторите ввод: ";
			continue;
		}
		else {
			break;
		}
	}

	std::cout << "Введите на сколько секунд включен двигатель: ";
	while (1) {
		std::cin >> t;
		if (t < 0) {
			std::cout << "Время включения двигателя не может быть меньше нуля!\n";
			std::cout << "Повторите ввод: ";
			continue;
		}
		else {
			break;
		}
	}
	*/
	m = createFloat(false, "Введите массу звездолета(кг): ");
	f = createFloat(true, "Введите силу тяги(Н): ");
	t = createFloat(true, "Введите на сколько секунд включен двигатель(с): ");


	float s = (((f) / (m)) * t * t) / (2);

	std::cout << "Ваш аппарат будет на расстоянии " << s << " м от изначального положения\n";

}