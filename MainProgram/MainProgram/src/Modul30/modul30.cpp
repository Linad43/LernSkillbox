#include "header_modul30.h"

void modul30() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "30. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Реализовать пользовательские запросы.\n";
		std::cout << "2. Реализовать захват заголовка HTML-страницы.\n";
		std::cout << "3. Реализовать запросы разных типов с аргументами.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod30ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod30ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod30ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}