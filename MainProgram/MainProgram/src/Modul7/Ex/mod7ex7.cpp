#include "header_modul7.h"

void mod7ex7() {
	std::cout << "7. Биолаборатория*.\n";
	int countBacter, countAnti;
	while (1) {
		std::cout << "Введите кол-во бактерий: ";
		std::cin >> countBacter;
		if (countBacter < 0) {
			std::cout << "Кол-во бактерий не может быть отрицательным\n";
			continue;
		}
		break;
	}
	while (1) {
		std::cout << "Введите кол-во антибиотика: ";
		std::cin >> countAnti;
		if (countAnti < 0) {
			std::cout << "Кол-во антибиотика не может быть отрицательным\n";
			continue;
		}
		break;
	}
	for (int i = 0; countBacter >= 0 && (countAnti * 10 - i * countAnti) >= 0; countBacter = (countBacter * 2) - (countAnti * 10 - i++ * countAnti))
	{
		std::cout << "После " << i << " часа бактерий осталось " << countBacter << "\n";
	}
}