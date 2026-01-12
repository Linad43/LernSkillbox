#include "header_modul11.h"

void modul11() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "11. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Шифр Цезаря.\n";
		std::cout << "2. Программа проверки корректности email-адреса.\n";
		std::cout << "3. Программа валидации IP-адреса.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod11ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod11ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod11ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}