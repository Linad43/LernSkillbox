#include "../include/header_coop_fun.h"

/**
 * Вывод русского текста в консоли
 */
void rusText() {// 1251 65001 866
	//std::setlocale(0, "");
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	system("chcp 65001");
}