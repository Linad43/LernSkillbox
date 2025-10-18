#include "..\header_modul18.h"

void swapvec(std::vector <int>& vec, int arr[]) {
	if (typeid(vec[0]).name() == typeid(*arr).name()) {
		for (int i = 0; i < vec.size(); i++) {
			swap(&vec[i], (arr + i));
		}
	}
	else {
		std::cout << "Error\n";
	}
}

void mod18ex1() {
	std::cout << "1. Задача 1.\n";
	std::vector<int> a = { 1,2,3,4 };
	int b[] = { 2,4,6,8 };
	swapvec(a, b);
	for (int i = 0; i < 4; ++i)
		std::cout << a[i];
	std::cout << std::endl;
	for (int i = 0; i < 4; ++i)
		std::cout << b[i];
	std::cout << std::endl;
}