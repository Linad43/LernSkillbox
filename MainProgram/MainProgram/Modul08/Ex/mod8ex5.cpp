#include "..\header_modul8.h"

void mod8ex5() {
	std::cout << "5. Кенийский бегун.\n";
	std::cout << "Ввод: \n";
	int distace = createFloat(false, "Привет, Сэм! Сколько километров ты сегодня пробежал: ");
	float tempo[100], average = 0;
	{
		char text[40];
		for (int i = 0; i < distace; i++)
		{
			std::sprintf(text, "Какой у тебя был темп на километре %d ", i + 1);
			tempo[i] = createFloat(false, text);
			average += tempo[i];
		}
	}
	average /= distace;
	int min = 0, sec = round(average);
	min = sec / 60;
	sec %= 60;
	std::cout << "Вывод: \n";
	std::cout << "Твой средний темп за тренировку: ";
	std::cout << min << " мин ";
	std::cout << sec << " сек\n";
}
