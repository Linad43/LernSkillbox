#include "..\header_modul22.h"

std::map <std::string, int> names;

bool addMap(std::string inputName) {
	std::string nameVer = checkName(inputName);
	if (nameVer == "") {
		return false;
	}
	if (names.find(nameVer) != names.end()) {
		names[nameVer]++;
	}
	else {
		names[nameVer] = 1;
	}
}

std::string getMap() {
	if (!names.empty()) {
		for (std::map <std::string, int>::iterator it = names.begin(); it != names.end(); it++) {
			if (it->second > 0) {
				it->second--;
				return it->first;
			}
		}
	}
	return "NULL";
}

void mod22ex2() {
	std::cout << "2. Регистратура.\n";
	std::string input;
	do {
		std::cout << "Input wait\n";
		std::cin >> input;
		if (strToLow(input) == "next") {
			std::cout << getMap() << std::endl;
		}
		else if (strToLow(input) == "q") {
			break;
		}
		else {
			if (!addMap(input)) {
				std::cout << "Error input\n";
			}
		}
	} while (true);
}