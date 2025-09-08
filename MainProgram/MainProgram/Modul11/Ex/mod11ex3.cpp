#include "..\header_modul11.h"

int checkNum(char symbol) {
	if (symbol >= '0' && symbol <= '9') {
		return symbol - int('0');
	}
	else if (symbol == '.') {
		return -1;
	}
	else return -2;
}

bool checkIPv4(std::string address) {
	std::string num[]{ "", "", "", "" };
	int indexNum = 0, intNum = 0, countPoint = 0;
	for (int i = 0; i < address.size(); i++) {
		if (checkNum(address[i]) >= 0) {
			if (i != address.size() - 1 &&
				num[indexNum].empty() &&
				checkNum(address[i]) == 0 &&
				checkNum(address[i + 1]) >= 0) {
				return false;
			}
			num[indexNum] += address[i];
			intNum = intNum * 10 + checkNum(address[i]);
		}
		else if (checkNum(address[i]) == -1) {
			countPoint++;
			if (countPoint > 3) {
				return false;
			}
			if (intNum < 0 || intNum > 255) {
				return false;
			}
			intNum = 0;
			if (num[indexNum].empty())
				return false;
			else
				indexNum++;
		}
		else {
			return false;
		}
	}
	if (intNum < 0 || intNum > 255) {
		return false;
	}
	if (num[indexNum].empty() && indexNum != 3)
		return false;
	return true;
}

void mod11ex3() {
	std::cout << "3. Программа валидации IP-адреса.\n";
	std::string nameIPv6;
	std::cin >> nameIPv6;
	if (checkIPv4(nameIPv6)) {
		std::cout << "Valid\n";
	}
	else {
		std::cout << "Invalid\n";
	}
}