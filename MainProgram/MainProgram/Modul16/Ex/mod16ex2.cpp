#include "..\header_modul16.h"

void mod16ex2() {
	std::cout << "2. Сшиватель дробных чисел.\n";
	std::cout << "Введите целую часть числа: ";
	int num_int;
	std::cin >> num_int;
	std::cout << "Введите дробную часть числа: ";
	std::string num_fract_str;
	std::cin >> num_fract_str;
	double num_fract = (std::stod(num_fract_str)) / pow(10, num_fract_str.size());
	double num = num_int + num_fract;
	std::cout << num << std::endl;
}