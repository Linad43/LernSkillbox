#include "..\header_modul14.h"
#define SIZE_MATRIX 5

void section(int matrix[SIZE_MATRIX][SIZE_MATRIX], int section[SIZE_MATRIX][SIZE_MATRIX], int heightSection) {
	for (int i = 0; i < SIZE_MATRIX; i++) {
		for (int j = 0; j < SIZE_MATRIX; j++) {
			if (matrix[i][j] >= heightSection) {
				section[i][j] = 1;
			}
			else {
				section[i][j] = 0;
			}
		}
	}
}

void mod14ex7() {
	std::cout << "7. Почти «Майнкрафт*.\n";

	std::cout << "Input matrix of heights:\n";
	int matrix[SIZE_MATRIX][SIZE_MATRIX] =
	{
		{5,5,5,5,5},
		{4,3,3,3,4},
		{3,2,2,2,3},
		{2,1,1,1,2},
		{1,1,2,1,1}
	};

	for(int i(0);i<SIZE_MATRIX;i++)
		for (int j(0); j < SIZE_MATRIX; j++) {
			std::cout << "matrix[" << i + 1 << "][" << j + 1 << "] = ";
			std::cin >> matrix[i][j];
		}

	for (int i(0); i < SIZE_MATRIX; std::cout<<std::endl, i++)
		for (int j(0); j < SIZE_MATRIX; std::cout << matrix[i][j++] << " ");
	std::cout << std::endl;
	int slice[SIZE_MATRIX][SIZE_MATRIX];
	std::cout << "Input slice: ";
	int heightSection;
	std::cin >> heightSection;
	section(matrix, slice, heightSection);
	for (int i(0); i < SIZE_MATRIX; std::cout << std::endl, i++)
		for (int j(0); j < SIZE_MATRIX; std::cout << slice[i][j++] << " ");
}