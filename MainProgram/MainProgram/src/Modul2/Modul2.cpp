#include "header_modul2.h"

void modul2() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "2.5 Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Улучшаем гонщика\n";
		std::cout << "2. Калькулятор стоимости товара\n";
		std::cout << "3. Время, время!\n";
		std::cout << "4. Непонятная квитанция\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod2ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod2ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod2ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod2ex4();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}
