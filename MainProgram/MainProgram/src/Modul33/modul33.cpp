#include "header_modul33.h"

void modul33() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "33. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Реализовать работу корзины с покупками.\n";
		std::cout << "2. Реализовать игру по ловле рыбы.\n";
		std::cout << "3. Реализовать реестр данных на шаблонах.\n";
		std::cout << "4. Найти среднее арифметическое число в массиве.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod33ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod33ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod33ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod33ex4();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}