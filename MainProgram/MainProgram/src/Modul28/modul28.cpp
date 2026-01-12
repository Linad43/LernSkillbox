#include "header_modul28.h"

void modul28() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "28. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Реализовать симуляцию заплыва на 100 метров.\n";
		std::cout << "2. Реализовать симуляцию работы вокзала.\n";
		std::cout << "3. Реализовать симуляцию работы кухни онлайн-ресторана.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod28ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod28ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod28ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}