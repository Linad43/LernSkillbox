#include "..\HeaderModul1.h"
void ex3() {
	std::cout << "3. �����, �����!\n";
	std::cout << "��� �������� ����������, ������� �������� ������ ��������� ������ �� �����.\n";
	std::cout << "������� ������������ �����: ";
	int timeWork = random(400, 500);
	std::cout << timeWork << std::endl;
	std::cout << "������� ����� ������ ������ �����? ";
	int timeClient = random(2, 5);
	std::cout << timeClient << std::endl;
	std::cout << "������� ����� ������ �������� �����? ";
	int timeStaff = random(2, 5);
	std::cout << timeStaff << std::endl;
	int countClients = timeWork / (timeClient + timeStaff);
	std::cout << "�� ����� ������� �";
	std::cout << timeWork;
	std::cout << "����� ������ ������ ���������";
	std::cout << countClients << "\n";
}