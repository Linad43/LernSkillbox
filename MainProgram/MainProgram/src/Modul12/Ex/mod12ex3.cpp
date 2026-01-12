#include "header_modul12.h"
#include <cassert>

float travelTime(float distance, float speed) {
	assert(speed > 0);
	return distance / speed;
}

void mod12ex3() {
	std::cout << "3. Использование assert.\n";
	float distance;
	std::cout << "Input distance: ";
	std::cin >> distance;
	float speed;
	std::cout << "Input speed: ";
	std::cin >> speed;
	std::cout << "Travel time: " << travelTime(distance, speed) << std::endl;
}