#include "..\HeaderModul4.h"

void mod4ex1() {
	std::cout << "1. Минимум из двух чисел\n";
	double a, b;
	std::cout << "Введите первое число:" << std::endl;
	std::cin >> a;
	std::cout << "Введите второе число:" << std::endl;
	std::cin >> b;

	if (a > b) {
		std::cout << "Второе число меньше: " << b << std::endl;
	}
	else if (b > a) {
		std::cout << "Первое число меньше: " << a << std::endl;
	}
	else {
		std::cout << "Чила равны: " << a << std::endl;
	}
}