#include "header_modul9.h"

bool checkTime(std::string time, int* hour, int* minute) {
	int countHour = 0, countMinute = 0, countDel = 0;
	*hour = 0;
	*minute = 0;
	if (time.length() > 5 || time.length() < 3) {
		return false;
	}
	else {
		for (int i = 0; i < time.length(); i++) {
			if (countDel == 0) {
				if (time[i] >= '0' && time[i] <= '9') {
					*hour = *hour * 10 + (time[i] - '0');
					countHour++;
					if (countHour > 2) {
						*hour = 0;
						return false;
					}
				}
				else if (time[i] == ':' || time[i] == '.') {
					countDel++;
				}
				else {
					return false;
				}
			}
			else {
				if (time[i] >= '0' && time[i] <= '9') {
					*minute = *minute * 10 + (time[i] - '0');
					countMinute++;
					if (countMinute > 2) {
						*minute = 0;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}

void inputTime(std::string time, int* hour, int* minute) {
	while (1) {
		if (!checkTime(time, hour, minute)) {
			std::cout << "Неверно введено время, попробуйте снова.\n";
			std::cin >> time;
			continue;
		}
		else {
			break;
		}
	}
}

void mod9ex1() {
	std::cout << "1. Время в пути.\n";
	std::cout << "Введите время отправления (HH:MM): \n";
	std::string timeSend;
	std::cin >> timeSend;
	int hourSend, minuteSend;
	inputTime(timeSend, &hourSend, &minuteSend);

	std::cout << "Введите время прибытия (HH:MM): \n";
	std::string timeGet;
	std::cin >> timeGet;
	int hourGet, minuteGet;
	inputTime(timeGet, &hourGet, &minuteGet);

	int hourResult, minuteResult, bufSend, bufGet;
	bufSend = hourSend * 60 + minuteSend;
	bufGet = hourGet * 60 + minuteGet;
	bufGet += (bufSend > bufGet) ? (24 * 60) : 0;

	minuteResult = bufGet - bufSend;
	hourResult = minuteResult / 60;
	minuteResult %= 60;

	std::cout << "Поездка составила " << hourResult << "ч. " << minuteResult << "мин.\n";
}