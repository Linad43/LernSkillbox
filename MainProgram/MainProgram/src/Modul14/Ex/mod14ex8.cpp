#include "header_modul14.h"

#define SIZE_FILED 10
#define MAX_SIZE_SHIP 4

//Способа сделать проще без классов я не нашел

void printFiled(char filed[SIZE_FILED][SIZE_FILED]) {
	std::cout << "\\| ";
	for (int i = 'A'; i < SIZE_FILED + 'A'; std::cout << char(i++) << " | ");
	std::cout << "\n-+---+---+---+---+---+---+---+---+---+---|\n";
	for (int i(0); i < SIZE_FILED; i++) {
		std::cout << i << "|";
		for (int j(0); j < SIZE_FILED; std::cout << " " << filed[i][j++] << " |");
		std::cout << "\n-+---+---+---+---+---+---+---+---+---+---|\n";
	}
}

int checkPointFirstMod14Ex8(char point) {
	if (point >= 'a' && point <= SIZE_FILED + 'a') {
		return point - 'a';
	}
	if (point >= 'A' && point <= SIZE_FILED + 'A') {
		return point - 'A';
	}
	return -1;
}

int checkPointSecondMod14Ex8(char point) {
	if (point >= '0' && point <= SIZE_FILED + '0') {
		return point - '0';
	}
	return -1;
}

bool emptyShip(int player[MAX_SIZE_SHIP]) {
	for (int i(0); i < MAX_SIZE_SHIP; i++) {
		if (player[i] != 0) {
			return false;
		}
	}
	return true;
}

int placeShipOnePoint(int point[2], char filed[SIZE_FILED][SIZE_FILED], int player[4]) {
	if (player[0] <= 0) {
		return -3;
	}
	int x[2], y[2];
	for (int i(0); i < 2; i++) {
		if (point[i] - 1 < 0) {
			x[i] = 0;
		}
		else {
			x[i] = point[i] - 1;
		}
	}
	for (int i(0); i < 2; i++) {
		if (point[i] + 1 > 9) {
			y[i] = 9;
		}
		else {
			y[i] = point[i] + 1;
		}
	}
	if (filed[point[0]][point[1]] == ' ') {
		for (int i = x[0]; i <= y[0]; i++)
			for (int j = x[1]; j <= y[1]; filed[i][j++] = '.')
				filed[point[0]][point[1]] = 'O';
		return 0;
	}
	else {
		return -1;
	}

}

int placeShipTwoPoint(int point[2][2], char filed[SIZE_FILED][SIZE_FILED], int player[4]) {
	if (point[0][0] == point[1][0] || point[0][1] == point[1][1]) {
		int minPoint[2];
		int maxPoint[2];
		int indexEq;
		int equaly;
		if (point[0][0] == point[1][0]) {
			indexEq = 0;
			equaly = point[0][0];
		}
		else {
			indexEq = 1;
			equaly = point[0][1];
		}
		minPoint[indexEq] = equaly;
		maxPoint[indexEq] = equaly;

		if (point[0][(indexEq + 1) % 2] < point[1][(indexEq + 1) % 2]) {
			minPoint[(indexEq + 1) % 2] = point[0][(indexEq + 1) % 2];
			maxPoint[(indexEq + 1) % 2] = point[1][(indexEq + 1) % 2];
		}
		else {
			maxPoint[(indexEq + 1) % 2] = point[0][(indexEq + 1) % 2];
			minPoint[(indexEq + 1) % 2] = point[1][(indexEq + 1) % 2];
		}
		for (int i = minPoint[(indexEq + 1) % 2]; i <= maxPoint[(indexEq + 1) % 2]; i++) {
			if (indexEq == 0) {
				if (filed[equaly][i] != ' ') {
					return -1;
				}
			}
			else {
				if (filed[i][equaly] != ' ') {
					return -1;
				}
			}
		}
		if (maxPoint[(indexEq + 1) % 2] - minPoint[(indexEq + 1) % 2] > 4) {
			return -3;
		}
		if (player[maxPoint[(indexEq + 1) % 2] - minPoint[(indexEq + 1) % 2]] > 0) {
			int x[2], y[2];
			for (int i(0); i < 2; i++) {
				if (minPoint[i] - 1 < 0) {
					x[i] = 0;
				}
				else {
					x[i] = minPoint[i] - 1;
				}
			}
			for (int i(0); i < 2; i++) {
				if (maxPoint[i] + 1 > 9) {
					y[i] = 9;
				}
				else {
					y[i] = maxPoint[i] + 1;
				}
			}
			for (int i = x[0]; i <= y[0]; i++)
				for (int j = x[1]; j <= y[1]; filed[i][j] = '.', j++);
			for (int i = minPoint[(indexEq + 1) % 2]; i <= maxPoint[(indexEq + 1) % 2]; i++) {
				if (indexEq == 0) {
					filed[equaly][i] = 'O';
				}
				else {
					filed[i][equaly] = 'O';
				}
			}
		}
		else {
			return -3;
		}
		return maxPoint[(indexEq + 1) % 2] - minPoint[(indexEq + 1) % 2];
	}
	else {
		return -2;
	}
}

void twoPoint(std::string inputText, int point[2][2]) {
	if (inputText[2] == '-' && inputText.size() == 5) {
		point[0][1] = checkPointFirstMod14Ex8(inputText[0]);
		point[0][0] = checkPointSecondMod14Ex8(inputText[1]);
		point[1][1] = checkPointFirstMod14Ex8(inputText[3]);
		point[1][0] = checkPointSecondMod14Ex8(inputText[4]);
		for (int i(0); i < 2; i++) {
			for (int j(0); j < 2; j++) {
				if (point[i][j] == -1) {
					throw std::runtime_error("Enter exception!\n");
				}
			}
		}
	}
	else {
		throw std::runtime_error("Enter exception!\n");
	}
}

void onePoint(std::string inputText, int point[2]) {
	point[1] = checkPointFirstMod14Ex8(inputText[0]);
	point[0] = checkPointSecondMod14Ex8(inputText[1]);
}

void clearPoint(char filed[SIZE_FILED][SIZE_FILED]) {
	for (int i = 0; i < SIZE_FILED; i++) {
		for (int j = 0; j < SIZE_FILED; j++) {
			if (filed[i][j] == '.') {
				filed[i][j] = ' ';
			}
		}
	}
}

bool checkEndGame(char filed[SIZE_FILED][SIZE_FILED]) {
	for (int i = 0; i < SIZE_FILED; i++) {
		for (int j = 0; j < SIZE_FILED; j++) {
			if (filed[i][j] == 'O') {
				return true;
			}
		}
	}
	return false;
}

void placeShips(int player[MAX_SIZE_SHIP], char filed[2][SIZE_FILED][SIZE_FILED], int numFiled) {
	/*char filed[SIZE_FILED][SIZE_FILED];
	for (int i(0); i < SIZE_FILED; i++)
		for (int j(0); j < SIZE_FILED; filed[i][j] = filedOut[numFiled][i][j++]);*/
	std::string autoSetShip[2][10]{
		{"f0-f3","d5-d7","f5-h5","b2-b3",
		"i2-i3","g8-h8","h0","d2","b6","d9"},
		{"i1-i4","d0-d2","e9-g9","f1-g1",
		"a4-a5","h6-h7","e5","j6","b8","i9"}
	};
	int k = 0;
	while (!emptyShip(player)) {
		printFiled(filed[numFiled]);
		std::cout << "У вас осталось:\n";
		for (int i(0); i < MAX_SIZE_SHIP; std::cout << i + 1 << "-палубных: " << player[i] << std::endl, i++);
		std::cout << "Введите координату для однопалубных кораблей (a1)\nили диапазон для многопалубных(a1-a4):\n";
		std::string inputText;
		//std::cin >> inputText;
		inputText = autoSetShip[numFiled][k++];
		std::cout << inputText << std::endl;
		switch (inputText.size())
		{
		case 2: {
			int point[2];
			onePoint(inputText, point);
			switch (placeShipOnePoint(point, filed[numFiled], player))
			{
			case 0: {
				player[0]--;
				system("pause");
				system("cls");
				break;
			}
			case -3: {
				std::cout << "Корабли данного размера отсутствуют!\n";
				system("pause");
				system("cls");
				break;
			}
			default:
				std::cout << "Ошибка ввода!\n";
				system("pause");
				system("cls");
				break;
			}
			break;
		}
		case 5: {
			int point[2][2];
			twoPoint(inputText, point);
			switch (placeShipTwoPoint(point, filed[numFiled], player))
			{
			case 1: {
				player[1]--;
				system("pause");
				system("cls");
				break;
			}case 2: {
				player[2]--;
				system("pause");
				system("cls");
				break;
			}case 3: {
				player[3]--;
				system("pause");
				system("cls");
				break;
			}
			case -1: {
				std::cout << "Невозможно разместить корабль!\nПересечение, либо слишком близко к другому кораблю.\n";
				system("pause");
				system("cls");
				break;
			}
			case -2: {
				std::cout << "Корабли могут быть установлены только строго вертикально или горизонтально!\n";
				system("pause");
				system("cls");
				break;
			}
			case -3: {
				std::cout << "Корабли данного размера отсутствуют!\n";
				system("pause");
				system("cls");
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			std::cout << "Ошибка ввода!\n";
			system("pause");
			system("cls");
			break;
		}
		system("cls");
	}
	clearPoint(filed[numFiled]);
}

int checkShot(char filedHide[SIZE_FILED][SIZE_FILED], char parentFiled[SIZE_FILED][SIZE_FILED], int point[2]) {
	switch (parentFiled[point[0]][point[1]])
	{
	case ' ': {
		filedHide[point[0]][point[1]] = '*';
		parentFiled[point[0]][point[1]] = '*';
		return 0;
		break;
	}
	case 'O': {
		//bool monoShip = true;
		int pointShip[4][2] = { {point[0],point[1]},{-1,-1},{-1,-1},{-1,-1} };
		int shift[4][2] = { {-1,-1},{-1,-1},{-1,-1},{-1,-1} };
		int sizeShip = 1;
		int c = 1;
		for (int i = 0; i < 2; i++) {
			if (point[i] - 1 >= 0) {
				shift[i * 2][i] = point[i] - 1;
				shift[i * 2][(i + 1) % 2] = point[(i + 1) % 2];
			}
			if (point[i] + 1 <= 9) {
				shift[i * 2 + 1][i] = point[i] + 1;
				shift[i * 2 + 1][(i + 1) % 2] = point[(i + 1) % 2];
			}
		}
		bool inCycle = true;
		for (int i = 0; i < 4 && inCycle; i++) {
			if (shift[i][0] >= 0 && (parentFiled[shift[i][0]][shift[i][1]] == 'O' || parentFiled[shift[i][0]][shift[i][1]] == 'X')) {
				bool up = true;
				bool down = true;
				inCycle = false;
				int j = 0;
				if (shift[i][0] == point[0]) {
					bool findEndShip = true;
					while (findEndShip)
					{
						findEndShip = false;
						int nextShift = point[1] + (1 + j);
						if (nextShift >= 0 && up && (parentFiled[point[0]][nextShift] == 'O' || parentFiled[point[0]][nextShift] == 'X')) {
							pointShip[c][0] = point[0];
							pointShip[c++][1] = nextShift;
							if (parentFiled[shift[i][0]][nextShift] == 'O') {
								sizeShip++;
							}
							findEndShip = true;
						}
						else {
							up = false;
						}
						nextShift = point[1] - (1 + j);
						if (nextShift >= 0 && down && (parentFiled[point[0]][nextShift] == 'O' || parentFiled[point[0]][nextShift] == 'X')) {
							pointShip[c][0] = point[0];
							pointShip[c++][1] = nextShift;
							if (parentFiled[shift[i][0]][nextShift] == 'O') {
								sizeShip++;
							}
							findEndShip = true;
						}
						else {
							down = false;
						}
						j++;
					}
				}
				else {
					bool findEndShip = true;
					int j = 0;
					while (findEndShip)
					{
						findEndShip = false;
						int nextShift = point[0] + (1 + j);
						if (nextShift >= 0 && up && (parentFiled[nextShift][point[1]] == 'O' || parentFiled[nextShift][point[1]] == 'X')) {
							pointShip[c][1] = point[1];
							pointShip[c++][0] = nextShift;
							if (parentFiled[nextShift][point[1]] == 'O') {
								sizeShip++;
							}
							findEndShip = true;
						}
						else {
							up = false;
						}
						nextShift = point[0] - (1 + j);
						if (nextShift >= 0 && down && (parentFiled[nextShift][point[1]] == 'O' || parentFiled[nextShift][point[1]] == 'X')) {
							pointShip[c][1] = point[1];
							pointShip[c++][0] = nextShift;
							if (parentFiled[nextShift][point[1]] == 'O') {
								sizeShip++;
							}
							findEndShip = true;
						}
						else {
							down = false;
						}
						j++;
					}
				}
			}
		}
		parentFiled[point[0]][point[1]] = 'X';
		filedHide[point[0]][point[1]] = 'X';
		if (sizeShip == 1) {
			int pointMin[] = { pointShip[0][0],pointShip[0][1] };
			int pointMax[] = { pointShip[0][0],pointShip[0][1] };
			for (int i = 0; pointShip[i][0] >= 0; i++) {
				for (int j = 0; j < 2; j++) {
					if (pointShip[i][j] < pointMin[j]) {
						pointMin[j] = pointShip[i][j];
					}
					if (pointShip[i][j] > pointMax[j]) {
						pointMax[j] = pointShip[i][j];
					}
				}
			}
			for (int i = 0; i < 2; i++) {
				if (pointMin[i] - 1 >= 0) {
					pointMin[i] = pointMin[i] - 1;
				}
				if (pointMax[i] + 1 <= 9) {
					pointMax[i] = pointMax[i] + 1;
				}
			}
			for (int i = pointMin[0]; i <= pointMax[0]; i++) {
				for (int j = pointMin[1]; j <= pointMax[1]; j++) {
					if (filedHide[i][j] == ' ') {
						filedHide[i][j] = '.';
						parentFiled[i][j] = '.';
					}
					else if (filedHide[i][j] == 'X') {
						filedHide[i][j] = '#';
						parentFiled[i][j] = '#';
					}
				}
			}
		}
		return sizeShip;
	}
	default:
		break;
	}
	return -1;
}

void game(char filed[2][SIZE_FILED][SIZE_FILED]) {
	char filedHide[2][SIZE_FILED][SIZE_FILED];
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < SIZE_FILED; i++)
			for (int j = 0; j < SIZE_FILED; filedHide[k][i][j++] = ' ');
	int k = 0;
	std::string inputAttak;
	int point[2];
	while (checkEndGame(filed[0]) && checkEndGame(filed[1])) {
		std::cout << "Ход " << k << "-го игрока\n";
		printFiled(filedHide[k]);
		std::cout << "Введите координаты атаки(пример a4): ";
		std::cin >> inputAttak;
		onePoint(inputAttak, point);
		switch (checkShot(filedHide[k], filed[k], point))
		{
		case 0: {
			system("cls");
			std::cout << "Промах\n";
			printFiled(filedHide[k]);
			system("pause");
			system("cls");
			k = (k + 1) % 2;
			break;
		}
		case 1: {
			system("cls");
			std::cout << "Убил. ";
			break;
		}
		case 2: {
			system("cls");
			std::cout << "Попал. ";
			break;
		}
		case 3: {
			system("cls");
			std::cout << "Попал. ";
			break;
		}
		case 4: {
			system("cls");
			std::cout << "Попал. ";
			break;
		}
		default:
			break;
		}
	}
}

/*

\| a | b | c | d | e | f | g | h | i | j |
-+---+---+---+---+---+---+---+---+---+---|
0| * | X | # | O |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
1|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
2|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
3|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
4|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
5|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
6|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
7|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
8|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
9|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|

58
51 31
72 75

\| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
-+---+---+---+---+---+---+---+---+---+---|
0|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
1|   |   |   | O | O | O |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
2|   |   |   |   |   |   |   | O |   |   |
-+---+---+---+---+---+---+---+---+---+---|
3|   |   |   |   |   |   |   | O |   |   |
-+---+---+---+---+---+---+---+---+---+---|
4|   |   |   |   |   |   |   | O |   |   |
-+---+---+---+---+---+---+---+---+---+---|
5|   |   |   |   |   |   |   | O |   |   |
-+---+---+---+---+---+---+---+---+---+---|
6|   |   |   |   |   |   |   |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
7|   |   |   |   | . | . | . |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
8|   |   |   |   | . | O | . |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|
9|   |   |   |   | . | . | . |   |   |   |
-+---+---+---+---+---+---+---+---+---+---|

*/

void mod14ex8() {
	std::cout << "8. Морской бой*.\n";
	char filed[2][SIZE_FILED][SIZE_FILED];
	//char filed1[SIZE_FILED][SIZE_FILED];
	for (int k = 0; k < 2; k++)
		for (int i(0); i < SIZE_FILED; i++)
			for (int j(0); j < SIZE_FILED; filed[k][i][j++] = ' ');
	//char filed2[SIZE_FILED][SIZE_FILED];
	/*for (int i(0); i < SIZE_FILED; i++)
		for (int j(0); j < SIZE_FILED; filed2[i][j++] = ' ');*/
	std::cout << "Этап расстановки кораблей.\n";
	int player1[] = { 4,3,2,1 };
	int player2[] = { 4,3,2,1 };
	placeShips(player1, filed, 0);
	placeShips(player2, filed, 1);
	game(filed);
	system("cls");
	for (int i = 0; i < 2;i++) {
		std::cout << "Поле " << i + 1 << "-го игрока\n";
		printFiled(filed[i]);
		std::cout << std::endl;
	}
	if (checkEndGame(filed[0])) {
		std::cout << "Победа 1-го игрока\n";
	}
	else {
		std::cout << "Победа 2-го игрока\n";
	}
}