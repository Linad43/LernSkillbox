#include "header_modul6.h"

void mod6ex5() {
	std::cout << "5. Числа фибоначчи" << std::endl;
	int numFib;
	while (1) {
		std::cout << "Введите номер последовательности: ";
		std::cin >> numFib;
		if (numFib > 0 && numFib < 47) {
			break;
		}
		else
		{
			std::cout << "Неверное значение, число должно быть в пределах [1,46]\n";
		}
	}
	std::cout << "Число в последовательности: " << fibonacci(numFib) << "\n";
}
