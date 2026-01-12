#include "header_modul14.h"
#define COLUMN 12
#define ROW 3

void printArr(int arr[COLUMN][ROW]) {
	std::cout << "[";
	for (int i = 0; i < COLUMN; i++) {
		std::cout << "[";
		for (int j = 0; j < ROW; j++) {
			std::cout << arr[i][j];
			if (j != ROW - 1) {
				std::cout << ", ";
			}
		}
		std::cout << "]";
		if (i != COLUMN - 1) {
			std::cout << ", ";
			if (i % 2 != 0 && i != 0) {
				std::cout << std::endl;
			}
		}
	}
	std::cout << "]\n";
}

void mod14ex1() {
	std::cout << "1. Банкетный стол.\n";
	int packages[COLUMN][ROW];
	for (int i = 0; i < COLUMN; i++) {
		if (i == 0 || i == 1) {
			packages[i][0] = 4;
			packages[i][1] = 3;
		}
		else {
			packages[i][0] = 3;
			packages[i][1] = 2;
		}
		packages[i][2] = 1;
	}
	printArr(packages);
	std::cout << std::endl;
	packages[8][2]++;
	packages[5][0]--;
	packages[0][0]--;
	packages[5][0]++;
	packages[0][1]--;
	printArr(packages);
}