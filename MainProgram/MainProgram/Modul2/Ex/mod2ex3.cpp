#include "..\header_modul2.h"

void mod2ex3() {
    std::cout << "3. Время, время!\n";
    std::cout << "Эта програма рассчитает, сколько клиентов успеет обслужить кассир за смену.\n";
    std::cout << "Введите длительность смены: ";
    int timeWork = randomInt(400, 500);
    std::cout << timeWork << std::endl;
    std::cout << "Сколько минут клиент делает заказ? ";
    int timeClient = randomInt(2, 5);
    std::cout << timeClient << std::endl;
    std::cout << "Сколько минут кассир собирает заказ? ";
    int timeStaff = randomInt(2, 5);
    std::cout << timeStaff << std::endl;
    int countClients = timeWork / (timeClient + timeStaff);
    std::cout << "За смену длинной в";
    std::cout << timeWork;
    std::cout << "минут кассир успеет обслужить";
    std::cout << countClients << "\n";
}
