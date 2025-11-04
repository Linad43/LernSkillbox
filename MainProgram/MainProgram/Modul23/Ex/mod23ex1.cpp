#include "..\header_modul23.h"
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

void mod23ex1() {
	std::cout << "1. Реализовать продвинутый ввод и вывод дней недели.\n";
	int input;
	std::cin >> input;
	switch (input)
	{
		case MON:{
			std::cout << "Monday \n";
			break;
		}
		case TUE: {
			std::cout << "Tuesday \n";
			break;
		}
		case WED: {
			std::cout << "Wednesday \n";
			break;
		}
		case THU: {
			std::cout << "Thursday \n";
			break;
		}
		case FRI: {
			std::cout << "Friday \n";
			break;
		}
		case SAT: {
			std::cout << "Saturday \n";
			break;
		}
		case SUN: {
			std::cout << "Sunday \n";
			break;
		}
	default:
		break;
	}
}