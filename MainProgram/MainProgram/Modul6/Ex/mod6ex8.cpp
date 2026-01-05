#include "..\header_modul6.h"

void mod6ex8() {
    std::cout << "8. Угадай число" << std::endl;
    int i, min = 0, max = 64, choise;
    while (1) {
        i = randomInt(min, max - 1);
        while (1) {
            std::cout << "Задуманное число больше " << i << "? \n";
            std::cout << "1. Да\n";
            std::cout << "2. Нет\n";
            std::cin >> choise;
            if (choise > 0 && choise < 3) {
                break;
            }
        }
        if (choise == 1) {
            min = i + 1;
        } else {
            max = i;
        }
        if (max - min == 0) {
            std::cout << "Ваше число: " << min << std::endl;
            break;
        }
    }
}
