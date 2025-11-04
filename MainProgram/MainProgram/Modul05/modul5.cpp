#include "header_modul5.h"

void modul5() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "5.6 Практическая работа" << std::endl;
		std::cout << "Выберите задание:" << std::endl;
		std::cout << "1. Полет нормальный" << std::endl;
		std::cout << "2. Майские!" << std::endl;
		std::cout << "3. Майские - усложнение" << std::endl;
		std::cout << "4. Банкомат - 2" << std::endl;
		std::cout << "5. Усложнение задачи про кирпич" << std::endl;
		std::cout << "6. Грустное совершеннолетие" << std::endl << std::endl;
		std::cout << "0. Выход" << std::endl;

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod5ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod5ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod5ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod5ex4();
			system("pause");
			system("cls");
			break;
		};
		case 5: {
			system("cls");
			mod5ex5();
			system("pause");
			system("cls");
			break;
		};
		case 6: {
			system("cls");
			mod5ex6();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}