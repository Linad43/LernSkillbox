#include "header_modul12.h"

void modul12() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "12. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Многоквартирный дом.\n";
		std::cout << "2. Сортировка.\n";
		std::cout << "3. Использование assert.\n";
		std::cout << "4. Ряд чисел*.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod12ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod12ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod12ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod12ex4();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}