#include "header_modul12.h"
#define SIZE_ARR 15

void swap(float* pA, float* pB) {
	float buf;
	buf = *pA;
	*pA = *pB;
	*pB = buf;
}

void sort(float* pArr) {
	int i = 0, j = 1;
	while (j < SIZE_ARR - 1) {
		while (i < SIZE_ARR - j) {
			if (pArr[i] < pArr[i + 1]) {
				swap(&pArr[i], &pArr[i + 1]);
			}
			i++;
		}
		j++;
		i = 0;
	}
}

void mod12ex2() {
	std::cout << "2. Сортировка.\n";
	float arr[SIZE_ARR];
	std::cout << "Input " << SIZE_ARR << " float numbers:\n";
	for (int i = 0; i < SIZE_ARR; i++) {
		std::cin >> arr[i];
	}
	std::cout << "Input:\n";
	for (int i = 0; i < SIZE_ARR; i++) {
		std::cout << arr[i] << " ";
	}
	sort(arr);
	std::cout << "\nOutput:\n";
	for (int i = 0; i < SIZE_ARR; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}