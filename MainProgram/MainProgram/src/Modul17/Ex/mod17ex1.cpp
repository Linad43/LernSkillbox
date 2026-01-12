#include "header_modul17.h"

//void swap(int* a, int* b) {
//	int buf = *a;
//	*a = *b;
//	*b = buf;
//}

void mod17ex1() {
	std::cout << "1. Задача 1.\n";

	int a = 10;
	int b = 20;
	swap(&a, &b);

	std::cout << a << " " << b << std::endl;
}