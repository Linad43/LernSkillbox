#include "..\header_modul13.h"
#define SIZE_VECTOR 20

void printNumVector(const std::vector<int> vector, const int index) {
	int inIndex = index;
	for (int i = 0; i < vector.size(); i++) {
		if (vector[inIndex] != -1) {
			std::cout << vector[inIndex] << " ";
		}
		if (inIndex < SIZE_VECTOR-1) {
			inIndex++;
		}
		else {
			inIndex = 0;
		}
	}
	std::cout << std::endl;
}

void mod13ex3() {
	std::cout << "3. Exercise 3 (-2 exit).\n";
	std::vector<int> db(SIZE_VECTOR, -1);
	int index = 0;
	int num;
	while (true) {
		std::cout << "Input number: ";
		std::cin >> num;
		if (num == -1) {
			printNumVector(db, index);
			continue;
		}
		if (num == -2) {
			break;
		}
		db[index] = num;
		if (index == SIZE_VECTOR-1) {
			index = 0;
		}
		else {
			index++;
		}
	}
}