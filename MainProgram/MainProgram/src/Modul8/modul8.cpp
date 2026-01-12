#include "header_modul8.h"

void modul8() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "8.6 Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Космический симулятор\n";
		std::cout << "2. Immolate Improved!\n";
		std::cout << "3. Игрушечная история.\n";
		std::cout << "4. Убийца Steam.\n";
		std::cout << "5. Кенийский бегун.\n";
		std::cout << "6. Маятник.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod8ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod8ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod8ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod8ex4();
			system("pause");
			system("cls");
			break;
		};
		case 5: {
			system("cls");
			mod8ex5();
			system("pause");
			system("cls");
			break;
		};
		case 6: {
			system("cls");
			mod8ex6();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}