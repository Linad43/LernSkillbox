#include "..\HeaderModul1.h"
void ex2() {
	std::cout << "2. ����������� ��������� ������\n";
	int cost, costProd, costTf;
	std::cout << "������� ��������� ������: ";
	std::cin >> costProd;
	//costProd = 10;
	std::cout << costProd << "\n";
	std::cout << "������� ��������� ��������: ";
	std::cin >> costTf;
	//costTf = 5;
	std::cout << costTf << "\n";
	cost = costProd + costTf;
	std::cout << "������ ��������� ������: " << cost;
}