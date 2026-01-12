#include "header_modul23.h"
#define SPRING 0
#define SUMMER 1
#define AUTUMN 0
#define WINTER 0

void mod23ex2() {
	std::cout << "2. Реализовать вывод выбранного времени года.\n";
#if SPRING
	std::cout << "SPRING\n";
#endif
#if SUMMER
	std::cout << "SUMMER\n";
#endif
#if AUTUMN
	std::cout << "AUTUMN\n";
#endif
#if WINTER
	std::cout << "WINTER\n";
#endif
}