#include "../include/header_coop_fun.h"

/**
 *
 * @return
 *
 * Получение текущего года
 */
int getCurrentYear() {
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    return 1900 + pTInfo->tm_year;
}

/**
 *
 * @param text Проверяемая строка
 * @return
 *
 * Проверка на то что в строке только буквы англ алфавита.
 */
bool isLackNum(std::string text) {
    for (int i = 0; i < text.size(); i++) {
        if ((text[i] < 'A' || text[i] > 'Z') &&
            (text[i] < 'a' || text[i] > 'z')) {
            return false;
        }
    }
    return true;
}


/**
 *
 * @param input Проверяемая строка
 * @param checkNumPhone Добавить в проверку знак '+'
 * @return
 *
 * Проверка на то что строка не содержит символов кроме цифр.
 */
bool isDigit(std::string input, bool checkNumPhone) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] < '0' || input[i] > '9') {
            if (checkNumPhone && input[i] != '+') {
                return false;
            }
            return false;
        }
    }
    return true;
}

/**
 *
 * @param input Проверяемая строка
 * @return
 *
 * Проверка на то что строка не содержит символов кроме цифр.
 */
bool isDigit(std::string input) {
    return isDigit(input, false);
}

/**
 *
 * @param input Проверяемая строка
 * @return
 *
 * Проверка, что введенное слово это имя
 */
std::string checkName(std::string input) {
    std::string result = "";
    if (input.size() > 2 && isLackNum(input)) {
        result = input;
    }
    return result;
}

/**
 *
 * @param input Проверяемая строка
 * @return
 *
 * Проверка, что введенная строка дата в формате ДД.ММ.ГГГГ
 */
std::string checkDate(std::string input) {
    std::string result = "";
    if (input.size() == 10) {
        std::vector<std::string> date = splitString(input, ".");
        if ((stoi(date[0]) > 0 && stoi(date[0]) < 31) &&
            (stoi(date[1]) > 0 && stoi(date[1]) <= 12) &&
            (stoi(date[2]) > 1900 && stoi(date[2]) <= getCurrentYear())) {
            result = input;
        }
    }
    return result;
}

/**
 *
 * @param input Проверяемая строка
 * @return Возврат положительного числа или -1 в случае ошибки
 *
 * Проверка, что введенная строка положительное число
 * или возврат -1 в случае ошибки.
 */
int checkPayment(std::string input) {
    int result;
    try {
        result = stoi(input);
    } catch (...) {
        result = -1;
    }
    if (result < 0) {
        result = -1;
    }
    for (int i = 0; i < input.size(); i++) {
        if (input[i] < '0' || input[i] > '9') {
            result = -1;
            break;
        }
    }
    return result;
}
