#include "..\header_modul9.h"


void mod9ex2() {
	std::cout << "2. Длинное вещественное число.\n";
	std::cout << "Введите число:\n";
	std::string number;
	bool negative = false, isNum = true;
	int countNum = 0;
	std::cin >> number;
	if (number[0] == '-') {
		negative = true;
	}
	for (int i = negative ? 1 : 0, countDel = 0; i < number.length(); i++) {
		if (number[i] >= '0' && number[i] <= '9') {
			countNum++;
		}
		else if (countDel == 0 && (number[i] == '.' || number[i] == ',')) {
			countDel++;
		}
		else {
			isNum = false;
			break;
		}
	}
	isNum = (isNum && countNum > 0) ? true : false;
	std::cout << "Введенно " << (isNum ? "" : "не ") << "корректное число.\n";
}