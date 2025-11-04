#include "header_modul4.h"

void modul4() {
	int choise = 1;
	while (choise > 0) {
		std::cout << "4.4 Практическая работа\n";
		std::cout << "Выберите задание:\n";
		std::cout << "1. Минимум из двух чисел\n";
		std::cout << "2. Складываем в уме\n";
		std::cout << "3. Проверка на чётное число\n";
		std::cout << "4. Калькулятор опыта\n";
		std::cout << "5. Кратность числа\n";
		std::cout << "6. Улучшим барберов\n";
		std::cout << "7. Меню ресторана\n";
		std::cout << "8. Зарплата (необязательная)\n";
		std::cout << "9. Прогрессивный налог (необязательная)\n";
		std::cout << "0. Выход\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			mod4ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			mod4ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			mod4ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			mod4ex4();
			system("pause");
			system("cls");
			break;
		};
		case 5: {
			system("cls");
			mod4ex5();
			system("pause");
			system("cls");
			break;
		};
		case 6: {
			system("cls");
			mod4ex6();
			system("pause");
			system("cls");
			break;
		};
		case 7: {
			system("cls");
			mod4ex7();
			system("pause");
			system("cls");
			break;
		};
		case 8: {
			system("cls");
			mod4ex8();
			system("pause");
			system("cls");
			break;
		};
		case 9: {
			system("cls");
			mod4ex9();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}