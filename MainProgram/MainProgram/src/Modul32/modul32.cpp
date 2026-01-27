#include "header_modul32.h"

void modul32() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "32. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Сделать JSON-документ с информацией о киноленте.\n";
		std::cout << "2. Проанализировать JSON-базу данных о фильмах.\n";
		std::cout << "3. Реализовать модель данных компании на языке proto2.\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod32ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod32ex2();
			system("pause");
			system("cls");
			break;
		};
		// case 3: {
		// 	system("cls");
		// 	mod32ex3();
		// 	system("pause");
		// 	system("cls");
		// 	break;
		// };
		default:
			choice = 0;
		}
	}
}