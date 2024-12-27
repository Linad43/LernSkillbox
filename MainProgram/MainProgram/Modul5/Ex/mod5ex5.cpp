#include "..\header_modul5.h"

void mod5ex5() {
	std::cout << "5. Усложнение задачи про кирпич" << std::endl;
	std::cout << "Размеры первой коробки" << std::endl;
	int a, b, c, m, n, k;
	bool flag;
	std::cout << "А = ";
	std::cin >> a;
	std::cout << "B = ";
	std::cin >> b;
	std::cout << "C = ";
	std::cin >> c;
	std::cout << "Размеры второй коробки" << std::endl;
	std::cout << "M = ";
	std::cin >> m;
	std::cout << "N = ";
	std::cin >> n;
	std::cout << "K = ";
	std::cin >> k;
	flag = 0;
	if (m < a) {
		if (n < b) {
			if (k < c) {
				flag = 1;
			}
		}
		else if (n < c) {
			if (k < b) {
				flag = 1;
			}
		}
	}
	else if (m < b) {
		if (n < a) {
			if (k < c) {
				flag = 1;
			}
		}
		else if (n < c) {
			if (k < a) {
				flag = 1;
			}
		}
	}
	else if (m < c) {
		if (n < a) {
			if (k < b) {
				flag = 1;
			}
		}
		else if (n < b) {
			if (k < a) {
				flag = 1;
			}
		}
	}
}