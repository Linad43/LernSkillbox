#include "header_modul14.h"
#define SIZE_POP 12
void printPop(bool pop[SIZE_POP][SIZE_POP]) {
	std::cout << "\\\t";
	for (int i = 'A'; i < SIZE_POP + 'A'; std::cout << char(i++));
	std::cout << std::endl;
	for (int i = 0; i < SIZE_POP; std::cout << std::endl, i++) {
		std::cout << i + 1 << "\t";
		for (int j = 0; j < SIZE_POP; j++) {
			if (pop[i][j]) {
				std::cout << "O";
			}
			else {
				std::cout << "X";
			}
		}
	}
}
bool checkAll(bool pop[SIZE_POP][SIZE_POP]) {
	for (int i = 0; i < SIZE_POP; i++) {
		for (int j = 0; j < SIZE_POP; j++) {
			if (pop[i][j]) {
				return true;
			}
		}
	}
	return false;
}

int checkPointFirstMod14Ex5(std::string point) {
	if (point[0] >= 'a' && point[0] < 'a' + SIZE_POP) {
		return point[0] - 'a';
	}
	if (point[0] >= 'A' && point[0] < 'A' + SIZE_POP) {
		return point[0] - 'A';
	}
	return -1;
}
int checkPointSecondMod14Ex5(std::string point) {
	if (point.size() - 1 == 1) {
		if (point[1] >= '0' && point[1] <= '1' + SIZE_POP) {
			return point[1] - '0';
		}
	}
	else{
		int buf = 0;
		if (point[1] >= '0' && point[1] <= '9') {
			buf = (point[1] - '0') * 10;
			if (point[2] >= '0' && point[2] <= '9') {
				buf += point[2] - '0';
				return buf;
			}
		}
	}
	return -1;
}

void enterPointMod14Ex5(bool pop[SIZE_POP][SIZE_POP], std::string pointStart, std::string pointEnd) {
	int y1 = checkPointFirstMod14Ex5(pointStart);
	int x1 = checkPointSecondMod14Ex5(pointStart) - 1;
	int y2 = checkPointFirstMod14Ex5(pointEnd);
	int x2 = checkPointSecondMod14Ex5(pointEnd) - 1;
	if (pointStart.size() < 1 || pointStart.size() > 4 || x1 == -1 || y1 == -1) {
		throw std::runtime_error("Enter exception!\n");
	}
	if (pointEnd.size() < 1 || pointEnd.size() > 4 || x2 == -1 || y2 == -1) {
		throw std::runtime_error("Enter exception!\n");
	}
	if (x1 > x2) {
		int buf = x1;
		x1 = x2;
		x2 = buf;
	}
	if (y1 > y2) {
		int buf = y1;
		y1 = y2;
		y2 = buf;
	}
	for (int i = x1; i <= x2;i++) {
		for (int j = y1; j <= y2;j++) {
			if (pop[i][j]) {
				std::cout << "Pop! ";
			}
			pop[i][j] = false;
		}
	}
	std::cout << std::endl;
}

void mod14ex5() {
	std::cout << "5. Пупырка.\n";
	bool pop[SIZE_POP][SIZE_POP];
	std::string pointStart;
	std::string pointEnd;
	for (int i = 0; i < SIZE_POP; i++)
		for (int j = 0; j < SIZE_POP; pop[i][j++] = true);
	while (checkAll(pop)) {
		printPop(pop);
		std::cout << "Enter the begin coordinate(example A2) : ";
		std::cin >> pointStart;
		std::cout << "Enter the end coordinate(example A2) : ";
		std::cin >> pointEnd;
		try {
			enterPointMod14Ex5(pop, pointStart, pointEnd);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
}