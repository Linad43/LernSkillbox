#include "..\header_modul15.h"

void mod15ex4() {
	std::cout << "4. Exercise 4.\n";
	int arr[] = { -100,-50,-5,1,10,15 };
	int i = 0;
	int j = 0;
	while (true) {
		if (abs(arr[i]) > abs(arr[i + 1])) {
			i++;
		}
		else {
			j = i - 1;
			break;
		}
	}
	while (i < 6 && j >= 0) {
		if (abs(arr[i]) < abs(arr[j])) {
			std::cout << arr[i++] << " ";
		}
		else {
			std::cout << arr[j--] << " ";
		}
	}
	while (i < 6) {
		std::cout << arr[i++] << " ";
	}
	while (j >= 0) {
		std::cout << arr[j--] << " ";
	}
	std::cout << std::endl;
}