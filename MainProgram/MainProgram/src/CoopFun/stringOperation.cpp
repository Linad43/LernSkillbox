#include "header_coop_fun.h"

/**
 *
 * @param str Введенная строка
 * @return
 *
 * Кол-во символов в строке
 */
int lengthString(const char *str) {
    int i = 0;
    while (*(str + i) != '\0') {
        i++;
    }
    return i;
}

/**
 *
 * @param input Входная строка
 * @return
 *
 * Возврат строки в нижнем регистре.
 */
std::string stringToLower(std::string input) {
    std::string result = input;
    for (int i = 0; i < result.size(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

/**
 *
 * @param text Входная строка
 * @return
 *
 * Возврат строки без пробелов
 */
std::string delSpace(std::string text) {
    std::string result;
    auto buf = splitString(text, " ");
    for (int i = 0; i < buf.size(); i++) {
        result += buf[i];
    }
    return result;
}
