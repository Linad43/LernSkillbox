#include "header_coop_fun.h"

/**
 *
 * @param n Порядковый номер числа Фиббоначи
 * @return
 *
 * Возврат n-го числа Фиббоначи
 */
int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        int first, second, buf = 0;
        first = second = 1;
        int i = 2;
        while (i++ < n) {
            buf = first + second;
            first = second;
            second = buf;
        }
        return buf;
    }
}
