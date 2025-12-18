#include "..\include\header_modul25.h"

void modul25() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "25. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Реализовать симулятор проведения операций.\n";
		std::cout << "2. Создать модульный проект симулятора работы компьютера.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod25ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod25ex2();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}