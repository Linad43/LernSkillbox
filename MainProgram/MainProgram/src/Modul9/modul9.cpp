#include "header_modul9.h"

void modul9() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "9.7 Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Время в пути.\n";
		std::cout << "2. Длинное вещественное число.\n";
		std::cout << "3. Подсчёт количества слов.\n";
		std::cout << "4. «Быки и коровы»\n";
		std::cout << "5. Из обычных чисел — в римские.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod9ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod9ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod9ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod9ex4();
			system("pause");
			system("cls");
			break;
		};
		case 5: {
			system("cls");
			mod9ex5();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}