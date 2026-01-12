#include "header_modul8.h"

float createZeroToOne(const char* text) {
	std::cout << text;
	float var = 0;
	while (1) {
		std::cin >> var;
		if (var < 0 || var>1) {
			std::cout << "Значение должно  быть в пределах от 0 до 1!\n";
			continue;
		}
		else {
			break;
		}
	}
	return var;
}

void mod8ex2() {
	std::cout << "2. Immolate Improved!\n";
	float hpOrk, hpOrkMax, resMagic, dmgPow, dmg;
	hpOrkMax = createZeroToOne("Введите количество здоровья орка: ");
	hpOrk = hpOrkMax;
	while (hpOrk > 0) {
		std::cout << "Здоровье орка " << hpOrk << "/" << hpOrkMax << std::endl;
		resMagic = createZeroToOne("Введите сопротивление: ");
		dmgPow = createZeroToOne("Введите мощность удара: ");
		dmg = dmgPow * (1-resMagic);
		std::cout << "Урон " << dmgPow 
			<< ", сопротивляемость " << resMagic 
			<< ", по орку будет нанесено " << dmg << " урона.\n";
		hpOrk = hpOrk - dmg;
	}
	std::cout << "Вы победили орка\n";
}