#include "..\header_modul19.h"

int controlSum(char* sector) {
	int sum = 0;
	for (int i = 0; i < strlen(sector); sum += *(sector + i++));
	return sum;
}

void mod19ex5() {
	std::cout << "5. Реализовать версию игры «Что? Где? Когда?».\n";
	char sector[] = "aaaaaaaaaaaaa";
	std::ifstream file;
	int pointsPeople = 0, pointsGamers = 0;
	int answer, bufAnswer;
	int offset;
	int index = 0;
	while (controlSum != 0 && pointsPeople < 6 && pointsGamers < 6) {
		std::cout << "Input offset: ";
		std::cin >> offset;
		index += offset;
		index %= 13;
		while (sector[index] == 0) {
			index = (index + 1) % 13;
		}
		sector[index] = 0;
		char nameFile[50];
		char bufQuestion[20];
		sprintf(nameFile, ".\\Modul19\\game%d.txt", index);
		file.open(nameFile);
		file >> bufQuestion;
		std::cout << bufQuestion;
		file.close();
		sprintf(nameFile, ".\\Modul19\\answer%d.txt", index);
		file.open(nameFile);
		file >> bufAnswer;
		std::cin >> answer;
		if (bufAnswer == answer) {
			pointsGamers++;
		}
		else {
			pointsPeople++;
		}
		file.close();
		std::cout << "Players: " << pointsGamers << std::endl;
		std::cout << "People: " << pointsPeople << std::endl;
	}
	if (pointsGamers == 6) {
		std::cout << "Congratulations players WIN." << std::endl;
	}
	else {
		std::cout << "Congratulations people WIN." << std::endl;
	}
}