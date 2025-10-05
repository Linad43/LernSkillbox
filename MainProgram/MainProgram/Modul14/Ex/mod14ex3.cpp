#include "..\header_modul14.h"

bool identicalMatrix(float a[4][4], float b[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void printMatrixMod14Ex3(float a[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void mod14ex3() {
	std::cout << "3. Матрицы.\n";

	float matrixA[4][4] = {
		{1,2,3,4},
		{5,6,5,8},
		{9,0,1,2},
		{3,4,5,6}
	};
	float matrixB[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,0,1,2},
		{3,4,5,6}
	};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			std::cin >> matrixA[i][j];
		}
	}

	std::cout << std::endl;
	printMatrixMod14Ex3(matrixA);
	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << "B[" << i + 1 << "][" << j + 1 << "] = ";
			std::cin >> matrixB[i][j];
		}
	}

	std::cout << std::endl;
	printMatrixMod14Ex3(matrixB);
	std::cout << std::endl;

	if (identicalMatrix(matrixA, matrixB)) {
		std::cout << "Матрицы полностью равны\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i != j) {
					matrixA[i][j] = 0;
				}
			}
		}
		printMatrixMod14Ex3(matrixA);
	}
	else {
		std::cout << "Матрицы не равны\n";
	}
}