#include "header_modul30.h"
#include "cpr/cpr.h"

void getRequest(std::vector<std::pair<std::string, std::string> > *pairs) {
    std::string arg;
    for (auto it = pairs->begin(); it != pairs->end(); ++it) {
        if (it == pairs->begin()) {
            arg = "?";
        } else {
            arg += "&";
        }
        arg += it->first + "=" + it->second;
    }
    const std::string all = "https://httpbin.org/get" + arg;
    const cpr::Response r = cpr::Get(cpr::Url(all));
    std::cout << r.text << std::endl;
}

void postRequest(std::vector<std::pair<std::string, std::string> > *pairs) {
    // Создаем временный контейнер правильного типа
    std::vector<cpr::Pair> convertedPairs;
    for (const auto &[fst, snd]: *pairs) {
        convertedPairs.emplace_back(fst.c_str(), snd.c_str());
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
    std::string input;
    std::string first;
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
        } else if (!input.empty()) {
            if (isPair) {
                first = input;
            } else {
                std::string second = input;
                pairs->emplace_back(first, second);
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
