#include "header_coop_fun.h"

/**
 *
 * @param vec Вектор целочисленных значений
 *
 * Вывод значений через пробел, в конце перевод строки
 */
void printVector(const std::vector<int> &vec) {
    for (auto i{vec.begin()}; i != vec.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

/**
 *
 * @param vec Вектор вещественных значений
 *
 * Вывод значений через пробел, в конце перевод строки
 */
void printVector(const std::vector<float> &vec) {
    for (auto i{vec.begin()}; i != vec.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

/**
 *
 * @param vec Вектор строк
 *
 * Вывод значений через пробел, в конце перевод строки
 */
void printVector(const std::vector<std::string> &vec) {
    for (auto i{vec.begin()}; i != vec.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

/**
 *
 * @param vectorString Входной вектор строк
 * @return
 *
 * Возврат вектора вещественных значений из вектора строк.
 */
std::vector<float> vectorStrToFloat(const std::vector<std::string> &vectorString) {
    std::vector<float> result(vectorString.size());
    for (int i = 0; i < vectorString.size(); i++) {
        result[i] = stof(vectorString[i]);
    }
    return result;
}

/**
 *
 * @param vectorString Входной вектор строк
 * @return
 *
 * Возврат вектора целочисленных значений из вектора строк.
 */
std::vector<int> vectorStrToInt(const std::vector<std::string> &vectorString) {
    std::vector<int> result(vectorString.size());
    for (int i = 0; i < vectorString.size(); i++) {
        result[i] = stoi(vectorString[i]);
    }
    return result;
}
