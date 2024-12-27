#include "..\header_modul7.h"

void mod7ex8() {
	std::cout << "8. Ёлочка*.\n";
	int height, flag;
	std::cout << "Введите высоту елочки: ";
	std::cin >> height;

	if (height == 0) {
		std::cout << "\n";
	}
	else if (height > 0) {
		for (int j = 0; j < height; j++) {
			printMidKolon(height * 2 - 1, j * 2 + 1, '#', ' ');
		}
	}
	else {
		for (int j = -height; j > 0; j--) {
			printMidKolon(-height * 2 - 1, j * 2 - 1, '#', ' ');
		}
	}
}
