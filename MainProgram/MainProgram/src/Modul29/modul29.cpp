#include "header_modul29.h"

void modul29() {
    int choice = 1;
    while (choice > 0) {
        std::cout << "29. Практическая работа\n";
        std::cout << "Выберите задание:\n";
        std::cout << "1. Задача 1. Суперпёс.\n";
        std::cout << "2. Задача 2. Интерфейс Shape (по желанию).\n";
        std::cout << "0. Выход\n";

        std::cin >> choice;

        switch (choice) {
            case 1: {
                system("cls");
                mod29ex1();
                system("pause");
                system("cls");
                break;
            };
            case 2: {
                system("cls");
                mod29ex2();
                system("pause");
                system("cls");
                break;
            };
            default:
                choice = 0;
        }
    }
}
