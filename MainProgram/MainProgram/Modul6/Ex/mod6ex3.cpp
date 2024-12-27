#include "..\header_modul6.h"

void mod6ex3() {
	std::cout << "3. Коллекторы" << std::endl;
	int moneyBank, moneyPerson;
	char person[20];
	std::cout << "Введите имя должника: ";
	std::cin >> person;
	std::cout << "Введите сумму долга: ";
	std::cin >> moneyBank;
	if (moneyBank < 0) {
		std::cout << "Долг не может быть отрицательным\n";
		return;
	}
	moneyBank = -moneyBank;
	while (moneyBank < 0) {
		std::cout << "Ваш долг банку: " << -moneyBank << std::endl;
		std::cout << "Введите свой взнос " << person << ": ";
		std::cin >> moneyPerson;
		if (moneyPerson < 0) {
			std::cout << "Вы не можете брать в долг у банка, пока являетесь должником\n";
			continue;
		}
		moneyBank += moneyPerson;
	}
	std::cout << "Поздравляем, вы полностью погасили долг, на вашем счету: " << moneyBank << std::endl;
}