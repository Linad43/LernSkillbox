#include "header_modul22.h"

void modul22() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "22. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Телефонный справочник.\n";
		std::cout << "2. Регистратура.\n";
		std::cout << "3. Написать функцию, которая выводит анаграмму.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod22ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod22ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod22ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}