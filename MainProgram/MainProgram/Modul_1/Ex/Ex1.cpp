#include "..\HeaderModul1.h"
void ex1() {
	//ex1
	std::cout << "1. �������� �������\n";
	int lap = 4;
	//int speed = 358;
	int engine = 254;
	int wheels = 93;
	int steerinWheel = 49;
	int wind = 21;
	int rain = 17;
	int speed = engine + wheels + steerinWheel - (wind + rain);
	std::cout << "===================\n";
	std::cout << "����� �����. ���� " << lap << "\n";
	std::cout << "===================\n";
	std::cout << "������� (" << speed << ")\n";
	std::cout << "===================\n";
	std::cout << "��������: �������\n";
	std::cout << "��������: " << speed << "\n";
	std::cout << "-------------------\n";
	std::cout << "���������\n";
	std::cout << "���������: +" << engine << "\n";
	std::cout << "������: +" << wheels << "\n";
	std::cout << "����: +" << steerinWheel << "\n";
	std::cout << "-------------------\n";
	std::cout << "�������� ������ ������\n";
	std::cout << "�����: -" << wind << "\n";
	std::cout << "�����: -" << rain << "\n";
}