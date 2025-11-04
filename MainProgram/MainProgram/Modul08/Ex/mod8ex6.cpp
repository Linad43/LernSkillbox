#include "..\header_modul8.h"

void mod8ex6() {
	std::cout << "6. Маятник.\n";
	float amplitudeBeg = 0, amplitudeEnd = 0;
	while (1) {
		amplitudeBeg = createFloat(false, "Начальная амплитуда колебаний: ");
		amplitudeEnd = createFloat(false, "Конечная амплитуда колебаний: ");
		if (amplitudeBeg <= amplitudeEnd) {
			std::cout << "Начальная амплитуда должна быть больше конечной!\nПовторите ввод\n";
		}
		else {
			break;
		}
	}
	int i = 0;
	while (amplitudeBeg > amplitudeEnd) {
		std::cout << ++i << " амплитуда = " << amplitudeBeg << std::endl;
		amplitudeBeg *= (100 - 8.4)/100;
	}
	std::cout << "Количество затуханий " << i << std::endl;
}