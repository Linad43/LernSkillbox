#include "header_modul14.h"
#define RANG 4

void mod14ex6() {
	std::cout << "6. Проход змейкой*.\n";
	int numbers[RANG][RANG];
	int num = 0;
	int j = -1;
	for (int i = 0; i < RANG; i++) {
		j += pow(-1, i);
		while (j >= 0 && j < RANG) {
			numbers[i][j] = num;
			num++;
			j += pow(-1, i);
		}
	}
	for (int i = 0; i < RANG; std::cout << std::endl, i++)
		for (int j = 0; j < RANG; std::cout << "\t" << numbers[i][j++]);
}