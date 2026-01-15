#include "header_modul31.h"

void modul31() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "31. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Использование умного указателя.\n";
		std::cout << "2. Реализация умного указателя.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod31ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod31ex2();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}