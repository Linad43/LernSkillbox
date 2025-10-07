#include "..\header_modul15.h"
#define SIZE_DATA 4

void mod15ex2() {
	std::cout << "2. Exercise 2.\n";
	int inputData[] = { 2,7,11,15 };
	std::cout << "a = [";
	for (int i(0); i < SIZE_DATA; i++) {
		if (i != SIZE_DATA - 1) {
			std::cout << inputData[i] << ", ";
		}
		else {
			std::cout << inputData[i] << "]\n";
		}
	}
	int result, a, b;
	std::cout << "Input result: ";
	std::cin >> result;
	for (int i(0); i < SIZE_DATA; i++) {
		for (int j(i+1); j < SIZE_DATA; j++) {
			if (inputData[i] + inputData[j] == result) {
				a = inputData[i];
				b = inputData[j];
				break;
			}
		}
	}
	std::cout << a << " and " << b << std::endl;
}