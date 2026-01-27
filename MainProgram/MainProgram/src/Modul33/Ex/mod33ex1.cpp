#include "header_modul33.h"

void add(
    std::map<std::string, int> *products,
    const std::string &article,
    const int count
) {
    if (products->find(article) != products->end()) {
        products->at(article) += count;
    } else {
        products->insert({article, count});
    }
}

void remove(
    std::map<std::string, int> *products,
    const std::string &article,
    const int count
) {
    if (products->find(article) != products->end()) {
        if (products->at(article) == count) {
            products->erase(article);
        } else if (products->at(article) > count) {
            products->at(article) -= count;
        } else {
            throw std::invalid_argument("Count is too large!");
        }
    } else {
        throw std::invalid_argument("Not found article!");
    }
}

void inputProduct(
    std::string *article,
    int *count
) {
    std::cout << "Input your article and count product:\n";
    std::cin >> *article >> *count;
}

void mod33ex1() {
    std::cout << "1. Реализовать работу корзины с покупками.\n";
    std::string article, input;
    std::map<std::string, int> products;
    int count;
    while (true) {
        std::cout << "Input command:\n";
        std::cin >> input;
        if (input == "add") {
            inputProduct(&article, &count);
            try {
                add(&products, article, count);
            } catch (std::invalid_argument e) {
                std::cout << e.what() << '\n';
            }
        } else if (input == "remove") {
            inputProduct(&article, &count);
            try {
                remove(&products, article, count);
            } catch (std::invalid_argument e) {
                std::cout << e.what() << '\n';
            }
        } else if (input == "exit") {
            break;
        } else {
            std::cout << "Not found command, try again.\n";
        }
    }
}
