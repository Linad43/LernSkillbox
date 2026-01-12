#include "header_modul6.h"

void mod6ex4() {
	std::cout << "4. Счастливый билетик" << std::endl;
	int numTiket;
	int lenthNumTiket = 0;
	int buf, i = 0;
	while (1) {
		std::cout << "Введите номер билета: ";
		std::cin >> numTiket;
		if (numTiket < 0) {
			std::cout << "Номер билета не может быть отрицательным\n";
		}
		else break;
	}
	buf = numTiket;
	do {
		buf /= 10;
		lenthNumTiket++;

	} while (buf != 0);
	buf = numTiket;
	int sumBegin, sumEnd, numOne;
	sumBegin = sumEnd = 0;
	while (i < lenthNumTiket) {
		numOne = buf % 10;
		buf /= 10;
		if (i < lenthNumTiket / 2) {
			//std::cout << "sumBegin(" << sumBegin << ") += numOne(" << numOne << ")\n";
			sumBegin += numOne;
			//std::cout << "sumBegin = " << sumBegin << "\n";
		}
		else {
			//std::cout << "sumEnd(" << sumEnd << ") += numOne(" << numOne << ")\n";
			sumEnd += numOne;
			//std::cout << "sumEnd = " << sumEnd << "\n";
		}
		i++;
	}
	if (sumBegin == sumEnd) {
		std::cout << "Билет счастливый!\n";
	}
	else {
		std::cout << "Повезёт в следующий раз!\n";
	}
}