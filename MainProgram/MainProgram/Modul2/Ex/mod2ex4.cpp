#include "..\header_modul2.h"

void mod2ex4() {
	std::cout << "4. Непонятная квитанция\n";
	std::cout << "Приветствуем вас в калькуляторе квартплаты\n";
	int sumTot = random(10, 100) * 10000;
	std::cout << "Введите сумму, указанную в квитанции: " << sumTot << "\n";
	int countSumHome = random(1, 10);
	std::cout << "Сколько подъездов в вашем доме? " << countSumHome << "\n";
	int countHome = random(3, 6) * random(1, 25);
	std::cout << "Сколько квартир в каждом подъезде? " << countHome << "\n";
	int sumOneHome = sumTot / (countSumHome * countHome);
	std::cout << "Каждая квартира должна платить по " << sumOneHome << "\n";
}