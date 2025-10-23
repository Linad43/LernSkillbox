#include "..\header_modul20.h"

void mod20ex2() {
	std::cout << "2. Рисование случайных картин.\n";
	std::string nameFile = ".\\Modul20\\pic.txt";
	std::ofstream file(nameFile);
	std::cout << "Input height: ";
	int height;
	std::cin >> height;
	std::cout << "Input width: ";
	int width;
	std::cin >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			file << (rand() % 2 == 0);
		}
		file << std::endl;
	}
	file.close();
}