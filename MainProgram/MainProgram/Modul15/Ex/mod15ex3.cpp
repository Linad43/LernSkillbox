#include "..\header_modul15.h"

void toLeftSort(int arr[4]) {
	for (int i = 0; i < 4; i++) {
		if (arr[i] > arr[i + 1]) {
			int buf = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = buf;
		} else break;
	}
}
void toRightSort(int arr[]) {
	for (int i = 4; i > 0; i--) {
		if (arr[i] < arr[i - 1]) {
			int buf = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = buf;
		} else break;
	}
}

void mod15ex3() {
	std::cout << "3. Exercise 3.\n";
	int arr[] = { -1,-1,-1,-1,-1 };
	std::cout << "Input:\n";
	int input = 0;
	do {
		std::cin >> input;
		if (input == -1) {
			if (arr[0] == -1) {
				std::cout << "Not found 5 num\n";
			}
			else {
				std::cout << arr[4] << std::endl;
			}
			continue;
		}
		else if (input != -2) {
			if (arr[0] == -1) {
				arr[0] = input;
				toLeftSort(arr);
			}
			else if(arr[4]>input) {
				arr[4] = input;
				toRightSort(arr);
			}
		}
	} while (input != -2);
}
