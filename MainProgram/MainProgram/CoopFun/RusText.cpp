﻿#include "header_coop_fun.h"
/*
Вывод русского текста в консоли
*/
void rusText() {// 1251 65001 866
	//std::setlocale(0, "");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//system("chcp 65001");
}