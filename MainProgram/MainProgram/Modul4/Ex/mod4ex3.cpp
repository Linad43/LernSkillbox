#include "..\HeaderModul4.h"

void mod4ex3() {
	std::cout << "3. Проверка на чётное число\n";
	int a;
	std::cout << "Введите число: " << std::endl;
	std::cin >> a;
	if (a % 2 == 0) {
		std::cout << "Число " << a << " - чётное" << std::endl;
	}
	else {
		std::cout << "Число " << a << " - нечётное" << std::endl;
	}
}