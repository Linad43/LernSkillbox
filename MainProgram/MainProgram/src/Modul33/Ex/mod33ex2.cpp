#include "header_modul33.h"

class myAccessException : public std::exception {
    const char *what() const noexcept override {
        return "Access fishing\n";
    }
};

void mod33ex2() {
    std::cout << "2. Реализовать игру по ловле рыбы.\n";

    std::string pond[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
    pond[randomInt(0, 8)] = "fish";
    int count = 0;
    while (count < 3) {
        int buf = randomInt(0, 8);
        if (pond[buf].empty()) {
            pond[randomInt(0, 8)] = "fake";
            ++count;
        }
    }
    count = 0;
    while (true) {
        std::cout << "Enter num sector (1-9):\n";
        std::string input;
        std::cin >> input;
        if (!isDigit(input) || (stoi(input) < 0 && stoi(input) > 9)) {
            throw std::invalid_argument("Invalid input number.");
        }
        ++count;
        if (pond[stoi(input) - 1] == "fish") {
            std::cout << "Used: " << count << " try\n";
            throw myAccessException();
            system("pause");
        } else if (pond[stoi(input) - 1] == "fake") {
            std::cout << "Used: " << count << " try\n";
            throw std::runtime_error("You catch boot.\n");
            system("pause");
        } else {
            std::cout << "Nothing, try again.\n";
        }
    }
}
