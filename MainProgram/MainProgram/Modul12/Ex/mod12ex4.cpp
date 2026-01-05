#include "..\header_modul12.h"
#define SIZE_ARR 15

void printArr(int arr[SIZE_ARR]) {
    std::cout << "arr[";
    for (int i = 0; i < SIZE_ARR; i++) {
        if (i != SIZE_ARR - 1) {
            std::cout << arr[i] << ",";
        } else {
            std::cout << arr[i];
        }
    }
    std::cout << "]\n";
}

void createNumbers(int x, int numbers[SIZE_ARR]) {
    int index;
    for (int i = 0; i < SIZE_ARR - 1; i++) {
        while (true) {
            index = randomInt(0, 14);
            /*std::cout << "x = " << x << " ";
            std::cout << "index = " << index << std::endl;
            printArr(numbers);*/
            if (numbers[index] == 0) {
                numbers[index] = x + i;
                break;
            }
        }
    }
    for (int i = 0; i < SIZE_ARR; i++) {
        if (numbers[i] == 0) {
            numbers[i] = x + randomInt(0, 14);
        }
    }
    printArr(numbers);
}

void findReplay(int x, int numbers[SIZE_ARR]) {
    int replNum[SIZE_ARR]{0};
    for (int i = 0; i < SIZE_ARR; i++) {
        replNum[numbers[i] - x] += 1;
        if (replNum[numbers[i] - x] > 1) {
            std::cout << "replay num: " << numbers[i] << std::endl;
            return;
        }
    }
}

void mod12ex4() {
    std::cout << "3. Ряд чисел* (дополнительное задание).\n";
    int x = randomInt(1, 1000);
    std::cout << "x = " << x << " ";
    int numbers[SIZE_ARR]{0};
    createNumbers(x, numbers);
    findReplay(x, numbers);
}
