#include "..\HeaderModul4.h"

void mod4ex6() {
	std::cout << "6. Улучшим барберов\n";

	int mansCount;
	int barbersCount;

	std::cout << "***Барбершоп-калькулятор***" << std::endl;
	std::cout << "Введите число мужчин в городе: " << std::endl;
	std::cin >> mansCount;

	std::cout << "Сколько уже барберов удалось нанять?" << std::endl;
	std::cin >> barbersCount;

	int mansPerDay = mansCount / 30;
	int mansPerBarber = 8;
	int mansPerBarbePerMonth = mansPerBarber * 30;
	std::cout << "Один барбер стрижет " << mansPerBarbePerMonth << " в месяц" << std::endl;
	int requiredBarberCount = mansCount / mansPerBarbePerMonth;
	if (mansCount % mansPerBarbePerMonth != 0) {
		requiredBarberCount++;
	}
	std::cout << "Необходимое число барберов: " << requiredBarberCount << std::endl;

	std::cout << requiredBarberCount << " барбера могут постричь " <<
		requiredBarberCount * mansPerBarbePerMonth << " мужчин за месяц" << std::endl;
	if (requiredBarberCount > barbersCount) {
		std::cout << "Нужно больше барберов!!!" << std::endl;
	}
	else {
		std::cout << "Барберов хватает." << std::endl;
	}
}