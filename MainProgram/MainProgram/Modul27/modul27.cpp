#include "header_modul27.h"

void modul27() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "27. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Иерархия геометрических фигур.\n";
		std::cout << "2. Симуляция работы компании.\n";
		std::cout << "3. Деревня эльфов.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod27ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod27ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod27ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}