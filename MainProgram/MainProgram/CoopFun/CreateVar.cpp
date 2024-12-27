#include "HeaderCoopFun.h"
int createInt(int flag, const char* text) {
	int var;
	while (1)
	{
		std::cout << text;
		std::cin >> var;
		if (flag == 0) {
			if (var < 0) {
				std::cout << "¬веденное значение не может быть отрицательным\n";
				continue;
			}
		}
		else if (flag > 0) {
			if (var <= 0) {
				std::cout << "¬веденное значение должно быть выше нул€\n";
				continue;
			}
		}
		break;
	}
	return var;
}
int createInt(int flag) {
	return createInt(flag, "¬ведите значение ");
}
float createFloat(int flag, const char* text) {
	float var;
	while (1)
	{
		std::cout << text;
		std::cin >> var;
		if (flag == 0) {
			if (var < 0) {
				std::cout << "¬веденное значение не может быть отрицательным\n";
				continue;
			}
		}
		else if (flag > 0) {
			if (var <= 0) {
				std::cout << "¬веденное значение должно быть выше нул€\n";
				continue;
			}
		}
		break;
	}
	return var;
}
float createFloat(int flag) {
	return createFloat(flag, "¬ведите значение ");
}