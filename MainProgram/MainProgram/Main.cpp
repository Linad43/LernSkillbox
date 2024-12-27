#include "HeaderMain.h"

int main() {
	rusText();
	int choise = 1;
	while (choise > 0) {
		std::cout << "Изучения С++ на SkillBox\n";
		std::cout << "Выберите модуль:\n";
		std::cout << "1. Модуль 1(Нет д/з)\n";
		std::cout << "2. Модуль 2\n";
		std::cout << "3. Модуль 3\n";
		std::cout << "4. Модуль 4\n";
		std::cout << "\n0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			std::cout << "Нет домашнего задания\n";
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			Modul2();
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			Modul3();
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			Modul4();
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}