#include "header_modul24.h"

void modul24() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "24. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Реализовать программу учёта времени.\n";
		std::cout << "2. Реализовать программу напоминания о днях рождения.\n";
		std::cout << "3. Реализация программы таймера.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod24ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod24ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod24ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}