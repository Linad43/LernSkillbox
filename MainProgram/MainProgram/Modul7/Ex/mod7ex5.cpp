#include "..\header_modul7.h"
#define SIZE_X 51
#define SIZE_Y 21


void mod7ex5() {
	std::cout << "5. Координатные оси.\n";
	for (int i = 0; i < SIZE_Y; i++) {
		for (int j = 0; j < SIZE_X; j++) {
			if (i == (SIZE_Y / 2)) {
				if (j == (SIZE_X / 2))	std::cout << "+";
				else if (j == SIZE_X - 1)std::cout << ">";
				else std::cout << "-";
			}
			else if (j == (SIZE_X / 2)) {
				if (i == 0) std::cout << "^";
				else std::cout << "|";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}