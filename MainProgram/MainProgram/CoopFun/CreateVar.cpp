#include "header_coop_fun.h"
/*
Ввод целочисленной переменной
	flag ->
		true - число должно быть положительным
		false - число должно быть больше нуля
	text ->
		текст который будет выводится перед вводом переменной
*/
int createInt(bool flag, const char* text) {
	int var = -1;
	while (1)
	{
		std::cout << text;
		std::cin >> var;
		if (flag) {
			if (var < 0) {
				std::cout << "Введенное значение не может быть отрицательным\n";
				continue;
			}
		}
		else {
			if (var <= 0) {
				std::cout << "Введенное значение должно быть выше нуля\n";
				continue;
			}
		}
		break;
	}
	return var;
}
int createInt(bool flag) {
	return createInt(flag, "Введите значение ");
}
/*
Ввод вещественной переменной
	flag ->
		true - число должно быть положительным
		false - число должно быть больше нуля
	text ->
		текст который будет выводится перед вводом переменной
*/
float createFloat(bool flag, const char* text) {
	float var = -1;
	while (1)
	{
		std::cout << text;
		std::cin >> var;
		if (flag) {
			if (var < 0) {
				std::cout << "Введенное значение не может быть отрицательным\n";
				continue;
			}
		}
		else {
			if (var <= 0) {
				std::cout << "Введенное значение должно быть выше нуля\n";
				continue;
			}
		}
		break;
	}
	return var;
}
float createFloat(bool flag) {
	return createFloat(flag, "Введите значение ");
}