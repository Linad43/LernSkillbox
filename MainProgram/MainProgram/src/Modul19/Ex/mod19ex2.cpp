#include "header_modul19.h"

void mod19ex2() {
	std::cout << "2. Разработать простейший просмотрщик текстовых файлов.\n";
	std::cout << "Enter file directory: ";
	std::string nameFile = ".\\Modul19\\words.txt";
	std::cin >> nameFile;
	std::ifstream file(nameFile, std::ios::binary);
	if (file.is_open()) {
		std::cout << "File is open. Content file:\n";
		char buf;
		while (!file.eof()) {
			file.read(&buf, sizeof(buf));
			std::cout << buf;
		}
		std::cout << std::endl << "End file.\n";
	}
	else {
		std::cout << "File is not found.\n";
	}
}