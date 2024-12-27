#include "HeaderModul3.h"

void Modul3() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "3.5 Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Симулятор маршрутки.\n";
		std::cout << "2. Обмен местами.\n";
		std::cout << "3. Злостные вредители.\n";
		std::cout << "4. Повышаем градус сложности*.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod3ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod3ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod3ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod3ex4();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}