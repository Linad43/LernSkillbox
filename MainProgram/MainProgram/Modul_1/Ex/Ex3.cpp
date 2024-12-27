#include "..\HeaderModul1.h"
void ex3() {
	std::cout << "3. ¬рем€, врем€!\n";
	std::cout << "Ёта програма рассчитает, сколько клиентов успеет обслужить кассир за смену.\n";
	std::cout << "¬ведите длительность смены: ";
	int timeWork = random(400, 500);
	std::cout << timeWork << std::endl;
	std::cout << "—колько минут клиент делает заказ? ";
	int timeClient = random(2, 5);
	std::cout << timeClient << std::endl;
	std::cout << "—колько минут кассир собирает заказ? ";
	int timeStaff = random(2, 5);
	std::cout << timeStaff << std::endl;
	int countClients = timeWork / (timeClient + timeStaff);
	std::cout << "«а смену длинной в";
	std::cout << timeWork;
	std::cout << "минут кассир успеет обслужить";
	std::cout << countClients << "\n";
}