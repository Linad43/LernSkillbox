#include "..\header_modul7.h"
#define MID '!'
#define ALL '~'

void printMidKolon(int countSum, int countMid, char mid, char all) {
	for (int i = 0; i < (countSum - countMid); i++) {
		if (i == (countSum - countMid) / 2) {
			for (int j = 0; j < countMid; j++) {
				std::cout << mid;
			}
		}
		std::cout << all;
	}
	if (countSum == countMid) {
		for (int i = 0; i < countMid; i++)
			std::cout << mid;
	}
	std::cout << '\n';
}

void mod7ex6() {
	std::cout << "6. Важные объявления.\n";
	int countSum, countMid;
	while (1) {
		while (1) {
			std::cout << "Введите общую длину колонтитула: ";
			std::cin >> countSum;
			if (countSum <= 0) {
				std::cout << "Длина колонтитула не может быть отрицательной или равной нулю\n";
				continue;
			}
			else break;
		}
		while (1) {
			std::cout << "Введите кол-во восклицательных знаков: ";
			std::cin >> countMid;
			if (countMid < 0) {
				std::cout << "Кол-во Восклицательных знаков не может быть отрицательным\n";
				continue;
			}
			else break;
		}
		if (countMid > countSum) {
			std::cout << "Кол-во восклицательных знаков не может быть больше общей длинны\n";
			continue;
		}
		printMidKolon(countSum, countMid, MID, ALL);
		break;
	}
}