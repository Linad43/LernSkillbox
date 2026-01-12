#include "header_modul14.h"

void printTable(char game[3][3]) {
	std::cout << "\\ A   B   C\n";
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1;
		for (int j = 0; j < 3; j++) {
			std::cout << " " << game[i][j] << " ";
			if (j != 2) {
				std::cout << "|";
			}
		}
		std::cout << std::endl;
		if (i != 2) {
			std::cout << " ---+---+---\n";
		}
	}
}

int checkPointFirstMod14Ex2(std::string point) {
	if (point[0] >= 'a' && point[0] <= 'c') {
		return point[0] - 'a';
	}
	if (point[0] >= 'A' && point[0] <= 'C') {
		return point[0] - 'A';
	}
	return -1;
}
int checkPointSecondMod14Ex2(std::string point) {
	if (point[1] >= '1' && point[1] <= '3') {
		return point[1] - '1';
	}
	return -1;
}

void enterPointMod14Ex2(char game[3][3], std::string point, char letter) {
	int y = checkPointFirstMod14Ex2(point);
	int x = checkPointSecondMod14Ex2(point);
	if (point.size() != 2 || x == -1 || y == -1 || game[x][y] != ' ') {
		throw std::runtime_error("Enter exception!\n");
	}
	game[x][y] = letter;
}
char checkingGame(char game[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (game[i][0] == game[i][1] && game[i][1] == game[i][2]) {
			return game[i][0];
		}
		if (game[0][i] == game[1][i] && game[1][i] == game[2][i]) {
			return game[0][i];
		}
	}
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2]) {
		return game[0][0];
	}
	if (game[2][0] == game[1][1] && game[1][1] == game[0][2]) {
		return game[2][0];
	}
	return ' ';
}
bool endGame(char game[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game[i][j] == ' ') {
				return true;
			}
		}
	}
	return false;
}

void mod14ex2() {
	std::cout << "2. Крестики-нолики.\n";
	/*
	  \ A   B   C
	0 1   |   |
	   ---+---+---
	1 2   |   |
	   ---+---+---
	2 3   |   |
	*/
	std::string point;
	char game[3][3];
	char letter = ' ';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = letter;
		}
	}
	bool flag = true;
	int i = 0;
	while (endGame(game)) {
		printTable(game);
		if (i % 2 == 0) {
			letter = 'X';
		}
		else {
			letter = 'O';
		}
		std::cout << "Player "<<letter<<"\nEnter the coordinate(example A2) : ";
		std::cin >> point;
		try {
			enterPointMod14Ex2(game, point, letter);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		if (checkingGame(game) == ' ') {
			i++;
			continue;
		}
		else {
			break;
		}
	}
	printTable(game);
	if (checkingGame(game) == ' ') {
		std::cout << "We have a draw." << std::endl;
	}
	else {
		std::cout << "Winner player " << checkingGame(game) << std::endl;
	}
}