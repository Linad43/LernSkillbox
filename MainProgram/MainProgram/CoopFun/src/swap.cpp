#include "../include/header_coop_fun.h"

/**
 *
 * @param a Первое значение
 * @param b Второе значение
 *
 * Обмен двух переменных значениями, без возврата.
 */
void swap(int *a, int *b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}
