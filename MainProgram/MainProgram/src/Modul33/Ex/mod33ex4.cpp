#include "header_modul33.h"

template<typename T>
void input(T array[8]) {
    std::cout << "Fill the array (8):\n";
    // double sum = 0;
    for (int i = 0; i < 8; ++i) {
        std::cin >> array[i];
        // sum += array[i];
    }
    // return sum / 8;
}

template<typename T>
double average(T array[8]) {
    double sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += array[i];
    }
    return sum / 8;
}

void mod33ex4() {
    std::cout << "4. Найти среднее арифметическое число в массиве.\n";
    int array[8];
    input(array);
    const double aver = average(array);
    std::cout << aver << std::endl;
}
