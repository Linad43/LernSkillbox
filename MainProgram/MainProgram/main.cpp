﻿#include "header_main.h"

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
		std::cout << "5. Модуль 5\n";
		std::cout << "6. Модуль 6\n";
		std::cout << "7. Модуль 7\n";
		std::cout << "8. Модуль 8\n";
		std::cout << "9. Модуль 9\n";
		std::cout << "10. Модуль 10\n";
		std::cout << "11. Модуль 11\n";
		std::cout << "12. Модуль 12\n";
		std::cout << "13. Модуль 13\n";
		std::cout << "14. Модуль 14\n";
		std::cout << "15. Модуль 15\n";
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
			modul2();
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			modul3();
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			modul4();
			system("cls");
			break;
		};
		case 5: {
			system("cls");
			modul5();
			system("cls");
			break;
		};
		case 6: {
			system("cls");
			modul6();
			system("cls");
			break;
		};
		case 7: {
			system("cls");
			modul7();
			system("cls");
			break;
		};
		case 8: {
			system("cls");
			modul8();
			system("cls");
			break;
		};
		case 9: {
			system("cls");
			modul9();
			system("cls");
			break;
		};
		case 10: {
			system("cls");
			modul10();
			system("cls");
			break;
		};
		case 11: {
			system("cls");
			modul11();
			system("cls");
			break;
		};
		case 12: {
			system("cls");
			modul12();
			system("cls");
			break;
		};
		case 13: {
			system("cls");
			modul13();
			system("cls");
			break;
		};
		case 14: {
			system("cls");
			modul14();
			system("cls");
			break;
		};
		case 15: {
			system("cls");
			modul15();
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}