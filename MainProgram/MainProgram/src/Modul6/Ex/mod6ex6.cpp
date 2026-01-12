#include "header_modul6.h"

void mod6ex6() {
	std::cout << "6. Вклады" << std::endl;
	int sumIn, sumOut;
	double percent;
	std::cout << "Введите размер вклада: ";
	std::cin >> sumIn;
	std::cout << "Введите процентную ставку: ";
	std::cin >> percent;
	percent /= 100;
	std::cout << "Введите желаемую сумму: ";
	std::cin >> sumOut;
	int buf = sumIn, i = 0;
	while (buf < sumOut) {
		buf *= (percent + 1);
		i++;
		//printf("%d год: %d\n", i, buf);
	}
	if (i >= 5) {
		std::cout << "Придётся подождать: " << i << " лет";
	}
	else if (i == 1) {
		std::cout << "Придётся подождать: " << i << " год";
	}
	else {
		std::cout << "Придётся подождать: " << i << " года";
	}
	std::cout << std::endl;
}