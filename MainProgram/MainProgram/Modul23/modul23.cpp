#include "header_modul23.h"

void modul23() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "23. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Реализовать продвинутый ввод и вывод дней недели.\n";
		std::cout << "2. Реализовать вывод выбранного времени года.\n";
		std::cout << "3. Реализовать анализ вагонов.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod23ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod23ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod23ex3();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}