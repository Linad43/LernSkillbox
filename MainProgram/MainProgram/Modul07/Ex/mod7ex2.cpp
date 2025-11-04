#include "..\header_modul7.h"
#define AMERICANO_WATER 300
#define LATTE_WATER 30
#define LATTE_MILK 270

void mod7ex2() {
	std::cout << "2. Кофемашина.\n";
	int water, milk, choise, countLatte, countAmericano;
	std::cout << "Введите количество воды в мл: ";
	std::cin >> water;
	std::cout << "Введите количество молока в мл: ";
	std::cin >> milk;
	countLatte = countAmericano = 0;
	while (water >= AMERICANO_WATER || water >= LATTE_WATER && milk >= LATTE_MILK) {
		std::cout << "Выберите напиток (1 - американо, 2 - латте): ";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			if (water < AMERICANO_WATER) {
				std::cout << "Недостаточно воды\n";
				break;
			}
			std::cout << "Ваш напиток готов\n";
			countAmericano++;
			water -= AMERICANO_WATER;
			break;
		case 2:
			if (water < LATTE_WATER) {
				std::cout << "Недостаточно воды\n";
				break;
			}
			if (milk < LATTE_MILK) {
				std::cout << "Недостаточно молока\n";
				break;
			}
			std::cout << "Ваш напиток готов\n";
			countLatte++;
			water -= LATTE_WATER;
			milk -= LATTE_MILK;
			break;
		default:
			std::cout << "Введенно не корректное значение, попробуйте снова\n";
			break;
		}
	}
	std::cout << "***Отчет***\n";
	std::cout << "Ингридиентов осталось:\n";
	std::cout << "\tВода: " << water << " мл\n";
	std::cout << "\tМолоко: " << milk << " мл\n";
	std::cout << "Кружек американо приготовлено: " << countAmericano << "\n";
	std::cout << "Кружек латте приготовлено: " << countLatte << "\n";
}