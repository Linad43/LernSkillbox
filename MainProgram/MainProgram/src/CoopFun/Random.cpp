#include "header_coop_fun.h"

/**
 *
 * @param min Минимальное значение(включительно)
 * @param max Максимально значение(включительно)
 * @return
 *
 * Возврат случайного целого числа в заданных пределах [min, max].
 */
int randomInt(int min, int max) {
    return (min + rand() % (max - min + 1));
}

/**
 *
 * @param min Минимальное значение(включительно)
 * @param max Максимальное значение(включительно)
 * @return
 *
 * Возврат вещественного значения в заданных пределах [min, max]
 */
float randomFloat(int min, int max) {
    int integer = randomInt(min, max - 1);
    double fract = randomInt(0, 1000) / 1000.0;
    return integer + fract;
}
