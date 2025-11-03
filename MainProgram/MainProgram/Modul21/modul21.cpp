#include "header_modul21.h"

void modul21() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "20. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Ведомость учёта.\n";
		std::cout << "2. Модель данных для посёлка.\n";
		std::cout << "3. Математический вектор.\n";
		std::cout << "4. Пошаговая ролевая игра (дополнительная задача).\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod21ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod21ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod21ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod21ex4();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}