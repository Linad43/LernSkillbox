#include "HeaderModul1.h"

void Modul1() {
	rusText();
	int choise = 1;
	while (choise > 0) {
		std::cout << "2.5 ������������ ������\n";
		std::cout << "�������� �������:\n";
		std::cout << "1. �������� �������\n";
		std::cout << "2. ����������� ��������� ������\n";
		std::cout << "3. �����, �����!\n";
		std::cout << "4. ���������� ���������\n";
		std::cout << "0. �����\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			ex1();
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			ex2();
			system("pause");
			system("cls");
			break;
		};
		case 3: {
			system("cls");
			ex3();
			system("pause");
			system("cls");
			break;
		};
		case 4: {
			system("cls");
			ex4();
			system("pause");
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}
