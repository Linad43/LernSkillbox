#include "header_modul4.h"

void mod4ex8() {
	std::cout << "8. Зарплата (необязательная)\n";

	int salary[3];
	std::cout << "Введите зарплату первого сотрудника: " << std::endl;
	std::cin >> salary[0];
	std::cout << "Введите зарплату второго сотрудника: " << std::endl;
	std::cin >> salary[1];
	std::cout << "Введите зарплату третьего сотрудника: " << std::endl;
	std::cin >> salary[2];
	int max = salary[0];
	int min = max;
	int sum = 0;
	for (int i = 0; i < lengthString((char*)salary); i++) {
		if (salary[i] > max) {
			max = salary[i];
		}
		if (salary[i] < min) {
			min = salary[i];
		}
		sum += salary[i];
	}
	std::cout << "Самая высокая зарплата " << max << std::endl;
	std::cout << "Разница между самой высокой зарплатой и самой низкой: " << max - min << std::endl;
	std::cout << "Средняя зарплата " << ((double)sum) / 3 << std::endl;
}