﻿#include "header_modul13.h"

void modul13() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "13. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Задание 1.\n";
		std::cout << "2. Задание 2.\n";
		std::cout << "3. Задание 3.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod13ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod13ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod13ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}