#include "header_modul15.h"

void modul15() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "15. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Exercise 1.\n";
		std::cout << "2. Exercise 2.\n";
		std::cout << "3. Exercise 3.\n";
		std::cout << "4. Exercise 4.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod15ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod15ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod15ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod15ex4();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}