#include "..\header_modul7.h"

void mod7ex4() {
	std::cout << "4. Рамка.\n";
	int width, heigth;
	std::cout << "Введите ширину и высоту рамки: ";
	std::cin >> width >> heigth;
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) {
				std::cout << "|";
			}
			else if (i == 0 || i == heigth - 1) {
				std::cout << "-";
			}
			else {
				std::cout << " ";
			}
			if (j == width - 1) {
				std::cout << "\n";
			}
		}
	}
}