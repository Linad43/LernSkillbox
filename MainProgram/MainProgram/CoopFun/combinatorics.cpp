#include "header_coop_fun.h"

/**
 *
 * @param a Кол-во элементов
 * @return Факториал или -1 в случае ошибки
 *
 * Рекурсивная функция поиска факториала.
 */
int factorial(int a) {
    if (a < 0) {
        return -1; //exception
    }
    if (a == 1 || a == 0) {
        return 1;
    }
    return a * factorial(a - 1);
}

/**
 *
 * @param n Кол-во всего вещей
 * @param m Кол-во взятых для комбинации
 * @return Кол-во перестановок или -1 в случае ошибки
 *
 * Перестановка, то есть, в какое количество последовательностей
 * можно разложить m - вещей взятых из n - вещей.
 *
 * Условие m <= n
 *
 * для примера n = 3, m = 2:
 *
 * A_m^n = ab, ac, ba, bc, ca, cb = 6
 */
int selectOrderNotRepetition(int n, int m) {
    if (m > n) {
        return -1; //exception
    }
    return factorial(n) / factorial(n - m);
}

/**
 *
 * @param n Кол-во всего вещей
 * @param m Кол-во взятых для комбинаций
 * @return Кол-во перестановок с повторениями или -1 в случае ошибки
 *
 * Перестановка, то есть, в какое количество последовательностей
 * можно разложить m - вещей взятых из n - вещей.
 * Возможны повторения.
 *
 * Условие m <= n
 *
 * для примера n = 3, m = 2:
 *
 * A_m^n = aa, ab, ac, ba, bb, bc, ca, cb, cc = 9
 */
int selectOrderRepetition(int n, int m) {
    if (m > n) {
        return -1; //exception
    }
    return pow(n, m);
}

/**
 *
 * @param n Кол-во всего вещей
 * @param m Кол-во взятых для комбинаций
 * @return Кол-во последовательностей или -1 в случае ошибки
 *
 * Выборка, то есть, в какое количество последовательностей
 * можно разложить m - вещей взятых из n - вещей
 * порядок не важен в данной перестановке,
 * то есть ab и ba это одна последовательность.
 *
 * Условие m <= n
 *
 * для примера n = 3, m = 2:
 *
 * A_m^n = ab, ac, bc = 3
 */
int selectNotOrderNotRepetition(int n, int m) {
    if (m > n) {
        return -1; //exception
    }
    return factorial(n) / (factorial(m) * factorial(n - m));
}

/**
 *
 * @param n Кол-во всего вещей
 * @param m Кол-во взятых для комбинаций
 * @return Кол-во последовательностей или -1 в случае ошибки
 *
 * Выборка, то есть, в какое количество последовательностей
 * можно разложить m - вещей взятых из n - вещей
 * порядок не важен в данной перестановке,
 * то есть ab и ba это одна последовательность.
 * Возможны повторения.
 *
 * Условие m <= n
 *
 * для примера n = 3, m = 2:
 *
 * A_m^n = aa, ab, ac, bb, bc, cc = 6
 */
int selectNotOrderRepetition(int n, int m) {
    if (m > n) {
        return -1; //exception
    }
    return factorial(n + m - 1) / (factorial(m) * factorial(n - 1));
}
