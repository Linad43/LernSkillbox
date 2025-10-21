#include "..\header_modul17.h"

//int lenghtStr(const char* str) {
//	int i = 0;
//	while (*(str + i) != '\0') {
//		i++;
//	}
//	return i;
//}

bool subStr(const char* mainStr, const char* subStr) {
	int lenghtMainStr = lenghtStr(mainStr);
	int lenghtSubStr = lenghtStr(subStr);
	int i = 0, j;
	while (i < lenghtMainStr - lenghtSubStr) {
		j = 0;
		while (*(mainStr + i + j) == *(subStr + j)) {
			if (j == lenghtSubStr - 1) {
				return true;
			}
			j++;
		}
		i++;
	}
	return false;
}

void mod17ex3() {
	std::cout << "3. Задача 3.\n";
	const char* a = "Hello world";
	const char* b = "wor";
	const char* c = "banana";
	std::cout << subStr(a, b) << " " << subStr(a, c) << std::endl;
}