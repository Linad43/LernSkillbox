#include "..\header_modul17.h"
#define SIZE 10

void reverse(int* a, int size) {
	for (int i = 0; i < size - i; swap(a + i, a + size - 1 - i), i++);
}

void mod17ex2() {
	std::cout << "2. Задача 2.\n";
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	for (auto num : a) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	reverse(a, SIZE);
	for (auto num : a) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}