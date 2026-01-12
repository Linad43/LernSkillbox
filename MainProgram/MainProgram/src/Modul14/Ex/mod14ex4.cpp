#include "header_modul14.h"

void printMatrixMod14Ex4(float a[4]) {
	for (int i = 0; i < 4; std::cout << a[i++] << " ");
}

void mulMatrix(float a[4][4], float b[4], float result[4]) {
	for (int i = 0, buf = 0; i < 4; result[i++] = buf, buf = 0)
		for (int j = 0; j < 4; buf += a[i][j] * b[j++]);
}

void mod14ex4() {
	std::cout << "4. Умножение матрицы на вектор.\n";

	float matrixA[4][4] = {
	{1,2,3,4},
	{5,6,5,8},
	{9,0,1,2},
	{3,4,5,6}
	};
	for (int i = 0; i < 4; std::cout << std::endl,i++)
		for (int j = 0; j < 4; std::cout << matrixA[i][j++] << " ");
	std::cout << std::endl;

	float vectorB[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; std::cout << vectorB[i++] << " ");
	std::cout << std::endl;

	float vectorC[4];
	mulMatrix(matrixA, vectorB, vectorC);

	printMatrixMod14Ex4(vectorC);
	std::cout << std::endl;

}