#include "header_main.h"

int main() {
    rusText();

    srand(time(NULL));

    int choise = 1;
    while (choise > 0) {
        std::cout << "Изучения С++ на SkillBox\n";
        std::cout << "Выберите модуль:\n";
        std::cout << "1. Модуль 1(Нет д/з)\n";
        std::cout << "2. Модуль 2\n";
        std::cout << "3. Модуль 3\n";
        std::cout << "4. Модуль 4\n";
        std::cout << "5. Модуль 5\n";
        std::cout << "6. Модуль 6\n";
        std::cout << "7. Модуль 7\n";
        std::cout << "8. Модуль 8\n";
        std::cout << "9. Модуль 9\n";
        std::cout << "10. Модуль 10\n";
        std::cout << "11. Модуль 11\n";
        std::cout << "12. Модуль 12\n";
        std::cout << "13. Модуль 13\n";
        std::cout << "14. Модуль 14\n";
        std::cout << "15. Модуль 15\n";
        std::cout << "16. Модуль 16\n";
        std::cout << "17. Модуль 17\n";
        std::cout << "18. Модуль 18\n";
        std::cout << "19. Модуль 19\n";
        std::cout << "20. Модуль 20\n";
        std::cout << "21. Модуль 21\n";
        std::cout << "22. Модуль 22\n";
        std::cout << "23. Модуль 23\n";
        std::cout << "24. Модуль 24\n";
        std::cout << "25. Модуль 25(Нет д/з)\n";
        std::cout << "26. Модуль 26\n";
        std::cout << "27. Модуль 27\n";
        std::cout << "28. Модуль 28\n";
        std::cout << "29. Модуль 29\n";
        std::cout << "30. Модуль 30\n";
        std::cout << "\n0. Выход\n";

        std::cin >> choise;

        switch (choise) {
            case 1: {
                system("cls");
                std::cout << "Нет домашнего задания\n";
                system("pause");
                system("cls");
                break;
            };
            case 2: {
                system("cls");
                modul2();
                system("cls");
                break;
            };
            case 3: {
                system("cls");
                modul3();
                system("cls");
                break;
            };
            case 4: {
                system("cls");
                modul4();
                system("cls");
                break;
            };
            case 5: {
                system("cls");
                modul5();
                system("cls");
                break;
            };
            case 6: {
                system("cls");
                modul6();
                system("cls");
                break;
            };
            case 7: {
                system("cls");
                modul7();
                system("cls");
                break;
            };
            case 8: {
                system("cls");
                modul8();
                system("cls");
                break;
            };
            case 9: {
                system("cls");
                modul9();
                system("cls");
                break;
            };
            case 10: {
                system("cls");
                modul10();
                system("cls");
                break;
            };
            case 11: {
                system("cls");
                modul11();
                system("cls");
                break;
            };
            case 12: {
                system("cls");
                modul12();
                system("cls");
                break;
            };
            case 13: {
                system("cls");
                modul13();
                system("cls");
                break;
            };
            case 14: {
                system("cls");
                modul14();
                system("cls");
                break;
            };
            case 15: {
                system("cls");
                modul15();
                system("cls");
                break;
            };
            case 16: {
                system("cls");
                modul16();
                system("cls");
                break;
            };
            case 17: {
                system("cls");
                modul17();
                system("cls");
                break;
            };
            case 18: {
                system("cls");
                modul18();
                system("cls");
                break;
            };
            case 19: {
                system("cls");
                modul19();
                system("cls");
                break;
            };
            case 20: {
                system("cls");
                modul20();
                system("cls");
                break;
            };
            case 21: {
                system("cls");
                modul21();
                system("cls");
                break;
            };
            case 22: {
                system("cls");
                modul22();
                system("cls");
                break;
            };
            case 23: {
                system("cls");
                modul23();
                system("cls");
                break;
            };
            case 24: {
                system("cls");
                modul24();
                system("cls");
                break;
            };
            /*case 25: {
                system("cls");
                modul25();
                system("cls");
                break;
            };*/
            case 26: {
                system("cls");
                modul26();
                system("cls");
                break;
            };
            case 27: {
                system("cls");
                modul27();
                system("cls");
                break;
            };
            case 28: {
                system("cls");
                modul28();
                system("cls");
                break;
            };
            case 29: {
                system("cls");
                modul29();
                system("cls");
                break;
            };
            case 30: {
                system("cls");
                modul30();
                system("cls");
                break;
            };
            default:
                choise = 0;
        }
    }
}
