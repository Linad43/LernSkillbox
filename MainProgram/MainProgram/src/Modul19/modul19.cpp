#include "header_modul19.h"

void modul19() {
	int choice = 1;
	while (choice > 0) {
		std::cout << "19. Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Разработать программу поиска слов в файле.\n";
		std::cout << "2. Разработать простейший просмотрщик текстовых файлов.\n";
		std::cout << "3. Реализовать программу чтения и анализа ведомости с выплатами.\n";
		std::cout << "4. Разработать детектор PNG-файла.\n";
		std::cout << "5. Реализовать версию игры «Что? Где? Когда?».\n";
		std::cout << "0. Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			system("cls");
			mod19ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod19ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod19ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod19ex4();
			system("pause");
			system("cls");
			break;
		};
		case 5: {
			system("cls");
			mod19ex5();
			system("pause");
			system("cls");
			break;
		};
		default:
			choice = 0;
		}
	}
}