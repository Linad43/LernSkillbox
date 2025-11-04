#include "..\header_modul8.h"

float createMinFive(const char* text) {
	std::cout << text;
	float var = 0;
	while (1) {
		std::cin >> var;
		if (var < 5) {
			std::cout << "Значение должно быть больше 5!\n";
			continue;
		}
		else {
			break;
		}
	}
	return var;
}

void mod8ex3() {
	std::cout << "3. Игрушечная история.\n";
	std::cout << "Введите размеры бруска:\n";
	float x = createMinFive("X = ");
	float y = createMinFive("Y = ");
	float z = createMinFive("Z = ");
	int nX = x / 5;
	int nY = y / 5;
	int nZ = z / 5;
	int countCub = nX * nY * nZ;
	std::cout << "Из этого бруска можно изготовить " << countCub 
		<< " кубиков.\n";
	int i = 2;
	if (countCub < pow(i, 3)) {
		std::cout << "Набор создать невозможно.\n";
	}
	else {
		while (countCub >= pow(i, 3)) {
			i++;
		}
		std::cout << "Из них можно создать набор из " << pow(--i, 3) 
			<< " кубиков.\n";
	}
}