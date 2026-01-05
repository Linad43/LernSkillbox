#include "..\header_modul19.h"

int countSubstr(std::ifstream& readFile, const char* findString) {
	int count = 0;
	char bufChar;
	int lenghtFindStr = lengthString(findString);
	int j = 0;
	while (!readFile.eof()) {
		readFile >> bufChar;
		if (bufChar == *(findString+j)) {
			j++;
			if (lenghtFindStr == j) {
				count++;
				j = 0;
			}
		}
		else {
			j = 0;
		}
	}
	return count;
}

void mod19ex1() {
	std::cout << "1. Разработать программу поиска слов в файле.\n";
	std::ifstream file;
	file.open(".\\Modul19\\words.txt");
	std::cout << countSubstr(file, "mall") << std::endl;
	file.close();
}