#include "..\HeaderModul1.h"
void ex4() {
	std::cout << "4. ���������� ���������\n";
	std::cout << "������������ ��� � ������������ ����������\n";
	int sumTot = random(10, 100) * 10000;
	std::cout << "������� �����, ��������� � ���������: " << sumTot << "\n";
	int countSumHome = random(1, 10);
	std::cout << "������� ��������� � ����� ����? " << countSumHome << "\n";
	int countHome = random(3, 6) * random(1, 25);
	std::cout << "������� ������� � ������ ��������? " << countHome << "\n";
	int sumOneHome = sumTot / (countSumHome * countHome);
	std::cout << "������ �������� ������ ������� �� " << sumOneHome << "\n";
}