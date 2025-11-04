#include "..\header_modul8.h"

void mod8ex4() {
	std::cout << "4. Убийца Steam.\n";
	std::cout << "Ввод: \n";
	float sizeFile = createFloat(false, "Укажите размер файла для скачивания: ");
	float downlandFile = 0;
	float connectSpeed = createFloat(false, "Какова скорость соединения: ");
	float itogSec = 0, sec = 1;
	int percent = 0;
	std::cout << "Вывод: \n";
	while (sizeFile > downlandFile) {
		if (downlandFile + connectSpeed > sizeFile) {
			sec = (sizeFile - downlandFile) / connectSpeed;
		}
		Sleep(sec * 1000);
		downlandFile += connectSpeed * sec;
		itogSec += sec;
		std::cout << "Прошло " << itogSec << " сек. ";
		percent = (downlandFile / sizeFile) * 100;
		std::cout << "Скачано " << downlandFile << " из " << sizeFile << " МБ (" << percent << "%)\n";
	}
	std::cout << "Загрузка завершена.\n";
}