#include "../include/header_coop_fun.h"

/**
 *
* @param flag true - число должно быть положительным; false - число должно быть больше нуля
 * @param text Текст, который будет выводиться перед вводом переменной
 * @return
 *
 * Ввод целочисленной переменной.
 */
int createInt(bool flag, char *text) {
    int var = -1;
    while (true) {
        std::cout << text;
        std::cin >> var;
        if (flag) {
            if (var < 0) {
                std::cout << "Input value cannot be negative \n";
                continue;
            }
        } else {
            if (var <= 0) {
                std::cout << "Input value must be positive \n";
                continue;
            }
        }
        break;
    }
    return var;
}

/**
 *
 * @param flag true - число должно быть положительным; false - число должно быть больше нуля
 * @param text Текст, который будет выводиться перед вводом переменной
 * @return
 *
 * Ввод целочисленной переменной.
 */
int createInt(bool flag, const char *text) {
    return createInt(flag, (char *) text);
}

/**
 *
 * @param flag  true - число должно быть положительным; false - число должно быть больше нуля
 * @return
 *
 * Ввод целочисленной переменной.
 */
int createInt(bool flag) {
    return createInt(flag, "Input value ");
}

/**
 *
 * @param flag true - число должно быть положительным; false - число должно быть больше нуля
 * @param text Текст, который будет выводиться перед вводом переменной
 * @return
 *
 * Ввод вещественной переменной.
 */
float createFloat(bool flag, char *text) {
    float var = -1;
    while (1) {
        std::cout << text;
        std::cin >> var;
        if (flag) {
            if (var < 0) {
                std::cout << "Input value cannot be negative \n";
                continue;
            }
        } else {
            if (var <= 0) {
                std::cout << "Input value must be positive \n";
                continue;
            }
        }
        break;
    }
    return var;
}

/**
 *
 * @param flag true - число должно быть положительным; false - число должно быть больше нуля
 * @param text Текст, который будет выводиться перед вводом переменной
 * @return
 *
 * Ввод вещественной переменной.
 */
float createFloat(bool flag, const char *text) {
    return createFloat(flag, (char *) text);
}

/**
 *
 * @param flag  true - число должно быть положительным; false - число должно быть больше нуля
 * @return
 *
 * Ввод вещественной переменной.
 */
float createFloat(bool flag) {
    return createFloat(flag, "Input value ");
}
