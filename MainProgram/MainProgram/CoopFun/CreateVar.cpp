#include "HeaderCoopFun.h"
int createInt(int flag, const char* text) {
	int var;
	while (1)
	{
		std::cout << text;
		std::cin >> var;
		if (flag == 0) {
			if (var < 0) {
				std::cout << "��������� �������� �� ����� ���� �������������\n";
				continue;
			}
		}
		else if (flag > 0) {
			if (var <= 0) {
				std::cout << "��������� �������� ������ ���� ���� ����\n";
				continue;
			}
		}
		break;
	}
	return var;
}
int createInt(int flag) {
	return createInt(flag, "������� �������� ");
}
float createFloat(int flag, const char* text) {
	float var;
	while (1)
	{
		std::cout << text;
		std::cin >> var;
		if (flag == 0) {
			if (var < 0) {
				std::cout << "��������� �������� �� ����� ���� �������������\n";
				continue;
			}
		}
		else if (flag > 0) {
			if (var <= 0) {
				std::cout << "��������� �������� ������ ���� ���� ����\n";
				continue;
			}
		}
		break;
	}
	return var;
}
float createFloat(int flag) {
	return createFloat(flag, "������� �������� ");
}