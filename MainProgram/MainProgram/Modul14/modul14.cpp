#include "header_modul14.h"

void modul14() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "14. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Банкетный стол.\n";
		std::cout << "2. Крестики-нолики.\n";
		std::cout << "3. Матрицы.\n";
		std::cout << "4. Умножение матрицы на вектор.\n";
		std::cout << "5. Пупырка.\n";
		std::cout << "6. Проход змейкой*.\n";
		std::cout << "7. Почти «Майнкрафт*.\n";
		std::cout << "8. Морской бой*.\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod14ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod14ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod14ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod14ex4();
			system("pause");
			system("cls");
			break;
		};
		case 5: {
			system("cls");
			mod14ex5();
			system("pause");
			system("cls");
			break;
		};
		case 6: {
			system("cls");
			mod14ex6();
			system("pause");
			system("cls");
			break;
		};
		case 7: {
			system("cls");
			mod14ex7();
			system("pause");
			system("cls");
			break;
		};
		case 8: {
			system("cls");
			mod14ex8();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}