#include "..\header_modul9.h"
#define MAX_LENGTH 20

int stringToNum(std::string numberText) {
	int num = 0;
	for (int i = 0; i < numberText.length(); i++) {
		if (numberText[i] < '0' || numberText[i] > '9') {
			return 0;
		}
		else {
			num = (num * 10) + (numberText[i] - '0');
		}
	}
	if (num > 3999) {
		return 0;
	}
	return num;
}

void mod9ex5() {
	std::cout << "5. Из обычных чисел — в римские.\n";
	//самое боольшое римское число по длинне MMMDCCCLXXXVIII(15+'\0')
	std::string numDecText, numRomeText = "";
	int numDec;
	while (1) {
		std::cout << "Введите целое число(1-3999):\n";
		std::cin >> numDecText;
		numDec = stringToNum(numDecText);
		if (numDec != 0) {
			break;
		}
		else {
			std::cout << "Не корректное значение, повторите ввод\n";
		}
	}
	int arrNum[] = { 1000, 500, 100, 50, 10, 5, 1 };
	char arrSymbol[] = { 'M','D','C','L','X','V','I' };
	std::string bufString;
	for (int i = numDecText.length() - 1, j = 0; i >= 0; i--, j++) {
		bufString = "";
		if ((numDecText[i] - '0') * pow(10, j) >= arrNum[6 - j * 2]
			&& (numDecText[i] - '0') * pow(10, j) <= arrNum[6 - j * 2] * 3) {
			for (int k = 0; k < numDecText[i] - '0'; k++) {
				bufString += arrSymbol[6 - j * 2];
			}
		}
		else if ((numDecText[i] - '0') * pow(10, j) == arrNum[5 - j * 2] - pow(10,j)) {
			bufString = arrSymbol[6 - j * 2];
			bufString += arrSymbol[5 - j * 2];
		}
		else if ((numDecText[i] - '0') * pow(10, j) >= arrNum[5 - j * 2]
			&& (numDecText[i] - '0') * pow(10, j) <= arrNum[5 - j * 2] + arrNum[6 - j * 2] * 3) {
			bufString = arrSymbol[5 - j * 2];
			for (int k = 0; k < (numDecText[i] - '0') % 5; k++) {
				bufString += arrSymbol[6 - j * 2];
			}
		}
		else {
			bufString = arrSymbol[6 - j * 2];
			bufString += arrSymbol[4 - j * 2];
		}
		numRomeText = bufString + numRomeText;
	}
	std::cout << numDecText << " => " << numRomeText << std::endl;
}
