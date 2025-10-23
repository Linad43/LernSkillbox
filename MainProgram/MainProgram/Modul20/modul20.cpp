#include "header_modul20.h"

void modul20() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "20. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Запись в ведомость учёта.\n";
		std::cout << "2. Рисование случайных картин.\n";
		std::cout << "3. Симуляция игры «Рыбалка».\n";
		std::cout << "4. Симуляция работы банкомата.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod20ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod20ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod20ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod20ex4();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}