#include "header_modul7.h"
#define EATING 4

void mod7ex1() {
	std::cout << "1. Запасы продовольствия.\n";
	int mass = 100;
	for (int i = 0; mass > 0; i++) {
		std::cout << "После ";
		std::cout << i;
		std::cout << " месяца у вас в запасе останется ";
		mass -= EATING;
		std::cout << mass;
		std::cout << " кг гречки\n";
	}
}