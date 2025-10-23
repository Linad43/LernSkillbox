#include "..\header_modul19.h"

void mod19ex4() {
	std::cout << "4. Разработать детектор PNG-файла.\n";
	std::cout << "Enter file directory: ";
	std::string nameFile = ".\\Modul19\\test.png";
	//std::cin >> nameFile;
	std::ifstream file(nameFile, std::ios::binary);

	if (file.is_open()) {
		std::cout << "File is find:\n";
		char buf;
		bool flag = true;
		int index = 0;
		while (!file.eof()) {
			file.read(&buf, sizeof(buf));
			switch (index)
			{
			case 0: {
				if (!(buf == -119)) {
					flag = false;
				}
				break;
			}
			case 1: {
				if (!(buf == 'P')) {
					flag = false;
				}
				break;
			}
			case 2: {
				if (!(buf == 'N')) {
					flag = false;
				}
				break;
			}
			case 3: {
				if (!(buf == 'G')) {
					flag = false;
				}
				break;
			}
			default:
				break;
			}
			if (!flag) {
				break;
			}
			index++;
		}
		if (flag) {
			std::cout << "File is PNG\n";
		}
		else {
			std::cout << "File is not PNG\n";
		}
	}
	else {
		std::cout << "File is not found.\n";
	}
}