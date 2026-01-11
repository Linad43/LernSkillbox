#include "..\header_modul30.h"
#include "cpr/cpr.h"

// using namespace std;
//
// // Функция для выполнения GET-запроса
// void getRequest(vector<pair<string, string>>& pairs) {
//     cpr::Parameters params(pairs.begin(), pairs.end()); // Используем встроенный способ добавления параметров
//     auto response = cpr::Get(cpr::Url{"https://httpbin.org/get"}, params);
//     cout << response.text << endl;
// }
//
// // Функция для выполнения POST-запроса
// void postRequest(const vector<pair<string, string>>& pairs) {
//     cpr::Payload payload(pairs.begin(), pairs.end()); // Использование Payload для передачи POST-данных
//     auto response = cpr::Post(cpr::Url{"https://httpbin.org/post"}, payload);
//     cout << response.text << endl;
// }

void getRequest(std::vector<std::pair<std::string, std::string> > *pairs) {
    std::string arg = "";
    for (auto it = pairs->begin(); it != pairs->end(); it++) {
        if (it == pairs->begin()) {
            arg = "?";
        } else {
            arg += "&";
        }
        arg += it->first + "=" + it->second;
    }
    std::string all = "https://httpbin.org/get" + arg;
    cpr::Response r = cpr::Get(cpr::Url(all));
    std::cout << r.text << std::endl;
}

void postRequest(std::vector<std::pair<std::string, std::string> > *pairs) {
    // Создаем временный контейнер правильного типа
    std::vector<cpr::Pair> convertedPairs;
    for (const auto &pair: *pairs) {
        convertedPairs.emplace_back(pair.first.c_str(), pair.second.c_str());
    }

    // Используем созданный контейнер
    cpr::Payload payload(convertedPairs.begin(), convertedPairs.end());

    auto response = cpr::Post(
        cpr::Url{"https://httpbin.org/post"},
        payload
    );

    std::cout << response.text << std::endl;
}

std::string getVector(std::vector<std::pair<std::string, std::string> > *pairs) {
    bool isPair = true;
    std::string input = "";
    std::string first, second;
    while (true) {
        std::cin >> input;
        if (input == "get" || input == "post") {
            if (isPair) {
                return input;
            } else {
                std::cout << "The pairs are incomplete\n";
                continue;
            }
        } else if (input == "exit") {
            return input;
        } else if (input != "") {
            if (isPair) {
                first = input;
            } else {
                second = input;
                pairs->push_back(std::make_pair(first, second));
            }
            isPair = !isPair;
        } else {
            continue;
        }
    }
}

void mod30ex3() {
    std::cout << "3. Реализовать запросы разных типов с аргументами.\n";
    std::string input;
    std::vector<std::pair<std::string, std::string> > pairs;
    while (true) {
        input = getVector(&pairs);
        if (input == "get") {
            getRequest(&pairs);
        } else if (input == "post") {
            postRequest(&pairs);
        } else if (input == "exit") {
            break;
        } else {
            continue;
        }
    }
}
