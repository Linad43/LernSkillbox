#include "..\header_modul5.h"

void mod5ex4() {
	std::cout << "5. Банкомат - 2" << std::endl;
	std::cout << "Какую сумму хотите снять?" << std::endl;
	int sum, num5k, num2k, num1k, num5h, num2h, num1h;
	std::cin >> sum;
	int buf = sum;
	if (sum % 100 == 0 && sum <= 150000 && sum > 0) {
		num5k = buf / 5000;
		buf %= 5000;
		num2k = buf / 2000;
		buf %= 2000;
		num1k = buf / 1000;
		buf %= 1000;
		num5h = buf / 500;
		buf %= 500;
		num2h = buf / 200;
		buf %= 200;
		num1h = buf / 100;
		buf %= 100;
		std::cout << "Вы получите на руки" << std::endl;
		std::cout << num5k << " купюр номиналом 5000" << std::endl;
		std::cout << num2k << " купюр номиналом 2000" << std::endl;
		std::cout << num1k << " купюр номиналом 1000" << std::endl;
		std::cout << num5h << " купюр номиналом 500" << std::endl;
		std::cout << num2h << " купюр номиналом 200" << std::endl;
		std::cout << num1h << " купюр номиналом 100" << std::endl;
	}
	else if (sum < 0) {
		std::cout << "Введенное значение не может быть меньше нуля" << std::endl;
	}
	else if (sum % 100 != 0) {
		std::cout << "Введенное значение должно быть кратно 100" << std::endl;
	}
	else {
		std::cout << "Вы не можете снять больше 150 000 р" << std::endl;
	}
}