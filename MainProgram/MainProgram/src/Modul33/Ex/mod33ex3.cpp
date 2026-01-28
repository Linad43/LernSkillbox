#include "header_modul33.h"
#include "nlohmann/detail/input/parser.hpp"

template<typename T1, typename T2>
class Registry {
public:
    T1 key;
    T2 value;

    Registry(T1 key, T2 value) {
        this->key = key;
        this->value = value;
    }

    std::string toString() {
        return "{" + key + "->" + value + "}";
    }
};

// class Registry {
//     std::vector<MyPair<std::string, std::string> > registryStrStr;
//     std::vector<MyPair<std::string, int> > registryStrInt;
//     std::vector<MyPair<std::string, double> > registryStrDob;
//     std::vector<MyPair<int, std::string> > registryIntStr;
//     std::vector<MyPair<int, int> > registryIntInt;
//     std::vector<MyPair<int, double> > registryIntDob;
//     std::vector<MyPair<double, std::string> > registryDobStr;
//     std::vector<MyPair<double, int> > registryDobInt;
//     std::vector<MyPair<double, double> > registryDobDob;
//
// public:
//     Registry(const std::string &key, const std::string &value) {
//         registryStrStr.emplace_back(key, value);
//     }
//
//     Registry(const std::string &key, int value) {
//         registryStrInt.emplace_back(key, value);
//     }
//
//     Registry(const std::string &key, double value) {
//         registryStrDob.emplace_back(key, value);
//     }
//
//     Registry(int key, const std::string &value) {
//         registryIntStr.emplace_back(key, value);
//     }
//
//     Registry(int key, int value) {
//         registryIntInt.emplace_back(key, value);
//     }
//
//     Registry(int key, double value) {
//         registryIntDob.emplace_back(key, value);
//     }
//
//     Registry(double key, const std::string &value) {
//         registryDobStr.emplace_back(key, value);
//     }
//
//     Registry(double key, int value) {
//         registryDobInt.emplace_back(key, value);
//     }
//
//     Registry(double key, double value) {
//         registryDobDob.emplace_back(key, value);
//     }
//
//     MyPair<std::string, std::string> find(std::string key) {
//         std::vector<>
//         for (auto & it : registryStrStr) {
//             if (it.key == key) {
//
//             }
//         }
//     }
// };

// int toInt(const std::string &input) {
//     if (isDigit(input)) {
//         return std::stoi(input);
//     } else {
//         throw std::invalid_argument("Invalid input.");
//     }
// }
//
// double toDouble(const std::string &input) {
//     auto result = splitString(input, ".");
//     if (result.size() != 2 && isDigit(result[0]) && isDigit(result[1])) {
//         return std::stoi(result[0]) + std::stoi(result[1]) / result[1].size();
//     } else {
//         throw std::invalid_argument("Invalid input.");
//     }
// }
//
// void inputKeyValue() {
//     std::cout << "Input pain key value:\n";
//     std::string key, value;
//     std::cin >> key >> value;
//     int valueInt;
//     double valueDouble;
//     try {
//         int keyInt = toInt(key);
//         try {
//             valueInt = toInt(value);
//             Registry(keyInt, valueInt);
//         } catch (...) {
//         }
//         try {
//             valueDouble = toDouble(value);
//             Registry(keyInt, valueDouble);
//         } catch (...) {
//         }
//         Registry(keyInt, value);
//     } catch (...) {
//     }
//     try {
//         double keyDouble = toDouble(key);
//         try {
//             valueInt = toInt(value);
//             Registry(keyDouble, valueInt);
//         } catch (...) {
//         }
//         try {
//             valueDouble = toDouble(value);
//             Registry(keyDouble, valueDouble);
//         } catch (...) {
//         }
//         Registry(keyDouble, value);
//     } catch (...) {
//     }
//     try {
//         valueInt = toInt(value);
//         Registry(key, valueInt);
//     } catch (...) {
//     }
//     try {
//         valueDouble = toDouble(value);
//         Registry(key, valueDouble);
//     } catch (...) {
//     }
//     Registry(key, value);
// }

void mod33ex3() {
    std::cout << "3. Реализовать реестр данных на шаблонах.\n";
    std::vector<Registry<std::string, std::string> > registry;
    std::string input;
    while (true) {
        std::cout << "Input command:\n";
        std::cin >> input;
        if (input == "add") {
            std::cout << "Input pair key value:\n";
            std::string key, value;
            std::cin >> key >> value;
            registry.emplace_back(key, value);
        }
        if (input == "remote") {
            std::cout << "Input key:\n";
            std::string key;
            std::cin >> key;
            for (auto it = registry.begin(); it != registry.end();) {
                if (key == it->key) {
                    registry.erase(it);
                    continue;
                }
                ++it;
            }
        }
        if (input == "print") {
            for (auto &it: registry) {
                std::cout << it.toString() << "\n";
            }
        }
        if (input == "find") {
            std::cout << "Input key:\n";
            std::string key;
            std::cin >> key;
            for (auto &it: registry) {
                if (it.key == key) {
                    std::cout << it.toString() << "\n";
                }
            }
        }
        if (input == "exit") {
            break;
        }
    }
}
