#include "header_modul2.h"

void mod2ex2() {
	std::cout << "2. Калькулятор стоимости товара\n";
	int cost, costProd, costTf;
	std::cout << "Введите стоимость товара: ";
	std::cin >> costProd;
	//costProd = 10;
	std::cout << costProd << "\n";
	std::cout << "Введите стоимость доставки: ";
	std::cin >> costTf;
	//costTf = 5;
	std::cout << costTf << "\n";
	cost = costProd + costTf;
	std::cout << "Полная стоимость товара: " << cost;
}