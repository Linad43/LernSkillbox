#include "header_modul18.h"

void modul18() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "18. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Задача 1.\n";
		std::cout << "2. Задача 2.\n";
		std::cout << "3. Задача 3.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod18ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod18ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod18ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}