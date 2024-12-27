#include "..\header_modul3.h"
#define PART_DRIVER 0.25
#define PART_FUEL 0.2
#define PART_REPAIR 0.2
#define PART_TAXES 0.2

void mod3ex1() {
	std::cout << "1. Симулятор маршрутки.\n";

	std::string stoping[] = {
		"Первая",
		"Вторая",
		"Третья",
		"Четвертая"
	};
	int countClient = 0;
	int sumMoney = 0;
	int cost = 20;

	for (int i = 0; i < size(stoping); i++) {
		std::cout << "Прибываем на остановку: ";
		std::cout << stoping[i] << std::endl;
		int passOut = 0;
		if (i == 0) {
			std::cout << "Это первая остановка, автобус пуст\n";
		}
		else if (i != size(stoping) - 1) {
			std::cout << "Сколько пассажиров вышло на остановке?\n";
			std::cin >> passOut;
		}
		int passIn = 0;
		if (i != size(stoping) - 1) {
			std::cout << "Сколько пассажиров зашло на остановке?\n";
			std::cin >> passIn;
		}
		else {
			std::cout << "Это конечная остановка, все пассажиры вышли\n";
		}

		sumMoney += passIn * cost;
		if (i != size(stoping) - 1) {
			std::cout << "Отправляемся с остановки ";
			std::cout << stoping[i] << ". ";
			countClient += passIn - passOut;
			std::cout << "Пассажиров в автобусе: ";
			std::cout << countClient << std::endl;
		}
		else {
			std::cout << "Поездка окончена\n";
		}
	}

	//итог
	int salaryDriver = sumMoney * PART_DRIVER;
	int costFuel = sumMoney * PART_FUEL;
	int taxes = sumMoney * PART_TAXES;
	int costRepair = sumMoney * PART_REPAIR;
	int result = sumMoney - (salaryDriver + costFuel + taxes + costRepair);
	std::cout << "Всего заработано " << sumMoney << std::endl;
	std::cout << "Зарплата водителя " << salaryDriver << std::endl;
	std::cout << "Расходы на топливо " << costFuel << std::endl;
	std::cout << "Налоги " << taxes << std::endl;
	std::cout << "Расходы на ремонт машины " << costRepair << std::endl;
	std::cout << "Итого доход " << result << std::endl;
}