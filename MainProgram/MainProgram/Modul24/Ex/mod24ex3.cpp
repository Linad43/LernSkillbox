#include "..\header_modul24.h"

void mod24ex3() {
	std::cout << "3. Реализация программы таймера.\n";
	std::time_t time = std::time(nullptr);
	std::tm local = *std::localtime(&time);
	std::chrono::seconds dura(1);
	std::string input;
	std::cout << "Input minuts and seconds(mm:ss):\n";
	std::cin >> std::get_time(&local, "%M:%S");
	time = mktime(&local);
	while (local.tm_min != 0 ||local.tm_sec!=0) {
		time--;
		std::this_thread::sleep_for(dura);
		system("cls");
		if (local.tm_min < 10) {
			std::cout << "0" << local.tm_min;
		}
		else {
			std::cout << local.tm_min;
		}
		std::cout << ":";
		if (local.tm_sec < 10) {
			std::cout << "0" << local.tm_sec;
		}
		else {
			std::cout << local.tm_sec;
		}
		std::cout << std::endl;
		local = *std::localtime(&time);
	}
	std::cout << "DING! DING! DING!\n";
}