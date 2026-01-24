#include "header_coop_fun.h"

/**
 *
 * @param str Входная строка
 * @param del Делитель строки
 * @return Вектор строк без делителя
 *
 * Разделение строки по делителю
 */
std::vector<std::string> splitString(const std::string &str, const std::string &del) {
    std::string str_in = str;
    std::vector<std::string> result;

    while (true) {
        auto pos = str_in.find(del);
        result.push_back(str_in.substr(0, pos));
        str_in = str_in.substr(pos + del.size());
        if (pos == std::string::npos || str_in.empty()) {
            break;
        }
    }
    return result;
}
