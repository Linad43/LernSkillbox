#include "HeaderMain.h"

int main() {
	rusText();
	int choise = 1;
	while (choise > 0) {
		std::cout << "�������� �++ �� SkillBox\n";
		std::cout << "�������� ������:\n";
		std::cout << "1. ������ 1(��� �/�)\n";
		std::cout << "2. ������ 2\n";
		std::cout << "\n0. �����\n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			system("cls");
			std::cout << "��� ��������� �������\n";
			system("pause");
			system("cls");
			break;
		};
		case 2: {
			system("cls");
			Modul1();
			system("cls");
			break;
		};
		default:
			choise = 0;
		}
	}
}