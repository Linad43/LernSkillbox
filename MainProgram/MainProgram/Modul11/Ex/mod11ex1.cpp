#include "..\header_modul11.h"
#define INT_A 65
#define COUNT_LETTERS 26

bool isUpLetter(char letter) {
	if (letter >= 'A' && letter <= 'Z') {
		return true;
	}
	else return false;
}
bool isSmollLetter(char letter) {
	if (letter >= 'a' && letter <= 'z') {
		return true;
	}
	else return false;
}
bool isLetter(char letter) {
	if (isUpLetter(letter) || isSmollLetter(letter)) {
		return true;
	}
	else return false;
}

std::string encrypt_ceasar(std::string text, int k) {
	std::string result = text;
	for (int i = 0; i < result.size(); i++) {
		if (isLetter(result[i])) {
			if (isUpLetter(result[i])) {
				result[i] = int(result[i]) + k;
				if (!isUpLetter(result[i])) {
					result[i] = int(result[i]) - COUNT_LETTERS;
				}
			}
			if (isSmollLetter(result[i])) {
				result[i] = int(result[i]) + k;
				if (!isSmollLetter(result[i])) {
					result[i] = int(result[i]) - COUNT_LETTERS;
				}
			}
		}
	}
	return result;
}

void mod11ex1() {
	std::cout << "1. Шифр Цезаря.\n";

	std::string text;
	std::cout << "Text: ";
	std::cin.ignore();
	getline(std::cin, text);

	int k;
	std::cout << "Code: ";
	std::cin >> k;

	k = k % COUNT_LETTERS;
	std::string result = encrypt_ceasar(text, k);
	std::cout << "Результат:\n";
	std::cout << result << std::endl;
}