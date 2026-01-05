#include "..\header_modul9.h"
#define MAX_SIZE 4

void mod9ex4() {
    std::cout << "4. «Быки и коровы»\n";
    char numComp[5];
    int num[4];
    for (int i = 0; i < MAX_SIZE; i++) {
        int buf = randomInt(0, 9);
        for (int j = i - 1; j >= 0; j--) {
            if (buf == num[j]) {
                j = i - 1;
                buf = randomInt(0, 9);
            }
        }
        num[i] = buf;
    }
    sprintf(numComp, "%d%d%d%d", num[0], num[1], num[2], num[3]);
    std::cout << "Компьютер загадал число (" << numComp << ")\n";
    std::cout << "Найди число, задуманное компьютером!\n";
    char numHuman[5];
    int bulls = 0, cows = 0;
    while (bulls != 4) {
        while (1) {
            std::cin >> numHuman;
            bool exceptionInput = false;
            for (int i = 0; i < MAX_SIZE - 1 && !exceptionInput; i++) {
                for (int j = i + 1; j < MAX_SIZE; j++) {
                    if (numHuman[i] == numHuman[j]) {
                        exceptionInput = true;
                        std::cout << "Ошибка ввода! Цифры не могут повторяться!\n";
                        std::cout << "Повторите ввод\n";
                        break;
                    }
                }
            }
            if (!exceptionInput) {
                break;
            }
        }
        bulls = 0;
        cows = 0;
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                if (numComp[i] == numHuman[j]) {
                    if (i == j) {
                        bulls++;
                    } else {
                        cows++;
                    }
                }
            }
        }
        std::cout << "быков = " << bulls;
        std::cout << " коров = " << cows;
        std::cout << std::endl;
    }
    std::cout << "Поздравляем\n";
}
