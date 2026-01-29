#include <unordered_set>
#include "header_modul34.h"

void mod34ex2() {
    std::cout << "2. Задание 2.\n";
    std::vector<int> list;
    for (int i = 0; i < 50000; ++i) {
        list.push_back(randomInt(0, 9));
    }
    auto lambda = [](const std::vector<int> &input) {
        std::unordered_set<int> seen;
        std::vector<int> uniqueNums;
        for (const auto &num: input) {
            if (seen.find(num) == seen.end()) {
                uniqueNums.push_back(num);
                seen.insert(num);
            }
        }
        return std::make_unique<std::vector<int> >(std::move(uniqueNums));
    };
    const auto nums = lambda(list);
    std::for_each(nums->begin(), nums->end(), [](auto &num) {
        std::cout << num << " ";
    });
}
