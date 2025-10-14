#include "header_modul16.h"

void modul16() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "16. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Спидометр.\n";
		std::cout << "2. Сшиватель дробных чисел.\n";
		std::cout << "3. Калькулятор.\n";
		std::cout << "4. Механическое пианино.\n";
		std::cout << "5. Умный дом.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod16ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod16ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod16ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod16ex4();
			system("pause");
			system("cls");
			break;
		};
		case 5: {
			system("cls");
			mod16ex5();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}