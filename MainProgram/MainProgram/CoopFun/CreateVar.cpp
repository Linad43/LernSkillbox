#include "header_coop_fun.h"
/*
Ввод целочисленной переменной
	flag -> 
		0 - число должно быть положительным
		1 - число должно быть больше нуля
	text ->
		текст который будет выводится перед вводом переменной
*/
int createInt(int flag, const char* text) {
	int var;
	while (1)
	{
		std::cout << text;
		std::cin >> var;
		if (flag == 0) {
			if (var < 0) {
				std::cout << "Введенное значение не может быть отрицательным\n";
				continue;
			}
		}
		else if (flag > 0) {
			if (var <= 0) {
				std::cout << "Введенное значение должно быть выше нуля\n";
				continue;
			}
		}
		break;
	}
	return var;
}
int createInt(int flag) {
	return createInt(flag, "Введите значение ");
}
/*
Ввод вещественной переменной
	flag ->
		0 - число должно быть положительным
		1 - число должно быть больше нуля
	text ->
		текст который будет выводится перед вводом переменной
*/
float createFloat(int flag, const char* text) {
	float var;
	while (1)
	{
		std::cout << text;
		std::cin >> var;
		if (flag == 0) {
			if (var < 0) {
				std::cout << "Введенное значение не может быть отрицательным\n";
				continue;
			}
		}
		else if (flag > 0) {
			if (var <= 0) {
				std::cout << "Введенное значение должно быть выше нуля\n";
				continue;
			}
		}
		break;
	}
	return var;
}
float createFloat(int flag) {
	return createFloat(flag, "Введите значение ");
}