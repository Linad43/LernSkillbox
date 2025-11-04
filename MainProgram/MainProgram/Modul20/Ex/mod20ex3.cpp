#include "..\header_modul20.h"

//void strToLow(std::string text) {
//	for (int i = 0; i < text.size(); i++) {
//		text[i] = tolower(text[i]);
//	}
//}

void removeFishInRiver(int indexBeg, int indexEnd) {
	const char* bufNameFile = ".\\Modul20\\bufRiver.txt";
	std::ofstream bufFile(bufNameFile, std::ios::binary);
	const char* nameFile = ".\\Modul20\\river.txt";
	std::ifstream file(nameFile, std::ios::binary);
	int index = 0;
	char buf;
	while (!file.eof()) {
		file.read(&buf, sizeof(buf));
		if (!file.eof() && (index<indexBeg || index>indexEnd)) {
			bufFile.write(&buf, sizeof(buf));
		}
		index++;
	}
	file.close();
	bufFile.close();
	remove(nameFile);
	rename(bufNameFile, nameFile);
}

void addFishToBasket(std::string nameFish) {
	const char* nameFile = ".\\Modul20\\basket.txt";
	std::fstream file(nameFile, std::ios::app);
	file << nameFish << std::endl;
	file.close();
}

void findFish(std::string nameFish, int& indexBeg, int& indexEnd) {
	char bufLetter;
	int index = 0;
	int j = 0;
	bool inName = false;
	const char* nameFile = ".\\Modul20\\river.txt";
	std::ifstream file(nameFile, std::ios::binary);
	while (!file.eof()) {
		file.read(&bufLetter, sizeof(bufLetter));
		if (bufLetter == nameFish[j]) {
			if (!inName) {
				inName = true;
				indexBeg = index;
			}
			j++;
			if (j == nameFish.size()) {
				indexEnd = index;
				break;
			}
		}
		else {
			if (inName) {
				inName = false;
				indexBeg = 0;
				indexEnd = 0;
				j = 0;
			}
		}
		index++;
	}
}

void mod20ex3() {
	std::cout << "3. Симуляция игры «Рыбалка».\n";
	int choise = 1;
	int countFishBasket = 0;
	do {
		std::cout << "What kind of fish are you going to catch?\n";
		std::string typeFish;
		std::cin >> typeFish;
		typeFish = strToLow(typeFish);
		int indexBeg = 0, indexEnd = 0;
		findFish(typeFish, indexBeg, indexEnd);
		if (indexEnd - indexBeg == typeFish.size() - 1) {
			removeFishInRiver(indexBeg, indexEnd);
			addFishToBasket(typeFish);
			countFishBasket++;
		}
		else {
			std::cout << "This fish not found in river.\n";
		}
		std::cout << "You catch " << countFishBasket << " fish.\n";
		std::cout << "Repeat?\n1. Yes\n0. No\n";
		std::cin >> choise;
	} while (choise == 1);
}