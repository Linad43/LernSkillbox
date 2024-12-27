#include "..\HeaderModul4.h"

void mod4ex9() {
	std::cout << "9. Прогрессивный налог (необязательная)\n";

	int salary;
	double tax = 0;
	std::cout << "Введите зарплату: " << std::endl;
	std::cin >> salary;
	if (salary < 0) {
		std::cout << "Ошибка ввода " << std::endl;
	}
	else {
		int buf = salary;
		if (buf > 50000) {
			tax += 0.3 * (buf - 50000);
			buf = 50000;
		}
		if (buf > 10000) {
			tax += 0.2 * (buf - 10000);
			buf = 10000;
		}
		if (buf <= 10000) {
			tax += 0.13 * (buf);
		}
	}
	std::cout << "Сумма налога: " << tax << std::endl;
}