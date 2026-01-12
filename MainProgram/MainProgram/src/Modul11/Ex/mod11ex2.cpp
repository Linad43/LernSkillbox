#include "header_modul11.h"

bool checkSymbolSecondPart(char symbol) {
	if (symbol >= 'A' && symbol <= 'Z' ||
		symbol >= 'a' && symbol <= 'z' ||
		symbol >= '0' && symbol <= '9' ||
		symbol == '-' ||
		symbol == '.') {
		return true;
	}
	return false;
}

bool checkSymbolFirstPart(char symbol) {
	if (checkSymbolSecondPart(symbol)) {
		return true;
	}
	else if (symbol == '!' ||
		symbol == '#' ||
		symbol == '$' ||
		symbol == '%' ||
		symbol == '&' ||
		symbol == '\'' ||
		symbol == '*' ||
		symbol == '+' ||
		symbol == '-' ||
		symbol == '/' ||
		symbol == '=' ||
		symbol == '?' ||
		symbol == '^' ||
		symbol == '_' ||
		symbol == '`' ||
		symbol == '{' ||
		symbol == '|' ||
		symbol == '}' ||
		symbol == '~') {
		return true;
	}
	else return false;
}

bool checkMail(std::string nameMail) {
	int countFirstPart = 0, countSecondPart = 0;
	for (int i = 0; i < nameMail.size(); i++) {
		if (nameMail[i] == '@') {
			if (i == 0 || countFirstPart != 0) {
				return false;
			}
			else {
				if (i < 64) {
					countFirstPart = i + 1;
					countSecondPart = nameMail.size() + 1 - countFirstPart;
				}
				else {
					return false;
				}
			}
		}
		else if (nameMail[i] == '.' && (i == 0 || nameMail[i - 1] == '.')) {
			return false;
		}
		else if (countFirstPart == 0) {
			if (!checkSymbolFirstPart(nameMail[i])) {
				return false;
			}
		} 
		else if (countFirstPart != 0) {
			if (!checkSymbolSecondPart(nameMail[i])) {
				return false;
			}
		}
	}
	if (countFirstPart <= 0 || countSecondPart <= 0 || countFirstPart >=64 ||countSecondPart >=64) {
		return false;
	}
	return true;
}

void mod11ex2() {
	std::cout << "2. Программа проверки корректности email-адреса.\n";
	std::cout << "Input email:\n";
	std::string nameMail;
	std::cin >> nameMail;
	if (checkMail(nameMail)) {
		std::cout << "Yes\n";
	}
	else {
		std::cout << "No\n";
	}
}