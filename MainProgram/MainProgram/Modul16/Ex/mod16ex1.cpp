#include "..\header_modul16.h"


void mod16ex1() {
	std::cout << "1. Спидометр.\n";
	float speed = 0, speed_delta;
	do {
		std::cout << "Speed delta: ";
		std::cin >> speed_delta;
		speed_delta = (round(speed_delta * 10)) / 10;
		speed += speed_delta;
		std::cout << "Speed: " << speed << std::endl;
	} while (speed <= -0.1 || speed >= 0.1);
}