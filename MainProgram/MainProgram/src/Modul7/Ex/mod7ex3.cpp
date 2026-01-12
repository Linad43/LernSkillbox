#include "header_modul7.h"
#include<conio.h>
#define SIZE_X 15
#define SIZE_Y 20

void mod7ex3() {
	std::cout << "3. Красный Марс.\n";
	std::cout << "Для завершения введите \"q\"\n";
	int pos_x = SIZE_X / 2;
	int pos_y = SIZE_Y / 2;
	char input;
	int flag = 1;
	while (flag) {
		std::cout << "Марсоход находится на позиции ";
		std::cout << pos_x << ", " << pos_y << ", ";
		std::cout << "введите команду:\n";
		input = _getch();
		std::cout << input << "\n";
		switch (input)
		{
		case 'q':
			flag = 0;
			std::cout << "Завершение работы программы\n";
			break;
		case 'w':
			(pos_y + 1) <= SIZE_Y ? pos_y++ : pos_y;
			break;
		case 's':
			(pos_y - 1) >= 1 ? pos_y-- : pos_y;
			break;
		case 'd':
			(pos_x + 1) <= SIZE_X ? pos_x++ : pos_x;
			break;
		case 'a':
			(pos_x - 1) >= 1 ? pos_x-- : pos_x;
			break;
		default:
			std::cout << "Неверные входные параметры!\n";
			break;
		}
	}
}