#include "..\header_modul24.h"
//int yearInSec() {
//	std::time_t tNow = std::time(nullptr);
//	std::tm* localNow = std::localtime(&tNow);
//	std::time_t tYear = std::time(nullptr);
//	std::tm* localYear = std::localtime(&tYear);
//	localYear->tm_year++;
//	return 
//}
const int oneDayInSec = 86400;

struct birthday {
	std::string name = "";
	std::time_t time = 0;

	std::string setName() {
		std::string inputName;
		std::cout << "Input name:\n";
		do {
			std::cin >> inputName;
			if (checkName(inputName) != "") {
				name = inputName;
				break;
			}
			std::cout << "Error input. Try again.\n";
		} while (true);
		return inputName;
	}
	void setName(std::string& inputName) {
		do {
			if (checkName(inputName) != "") {
				name = inputName;
				break;
			}
			std::cout << "Error input. Try again.\n";
			std::cin >> inputName;
		} while (true);
	}
	void setTime() {
		std::tm local = *std::localtime(&time);
		std::cout << "Input date(yy-mm-dd):\n";
		std::cin >> std::get_time(&local, "%y-%m-%d");
		time = mktime(&local);
	}
	void toString() {
		std::tm* local = std::localtime(&time);
		std::cout << name << " " << std::put_time(local, "%y/%m/%d") << std::endl;
	}
	int timeToNow() {
		int resultDay = 0;
		std::time_t copyBD = time;
		std::time_t t = std::time(nullptr);
		std::tm localNow = *std::localtime(&t);
		std::tm localBD = *std::localtime(&copyBD);
		while (localBD.tm_mday != localNow.tm_mday || localBD.tm_mon != localNow.tm_mon) {
			copyBD -= oneDayInSec;
			localBD = *std::localtime(&copyBD);
			resultDay++;
		}
		return resultDay;
	}
};

void mod24ex2() {
	std::cout << "2. Реализовать программу напоминания о днях рождения.\n";
	std::string input;
	std::vector <birthday> birthdays;
	birthday result;
	while (true) {
		if (result.setName() == "end") {
			if (birthdays.size() > 0) {
				result = birthdays[0];
				for (int i = 1; i < birthdays.size(); i++) {
					if (result.timeToNow() > birthdays[i].timeToNow()) {
						result = birthdays[i];
					}
				}
			}
			break;
		}
		result.setTime();
		birthdays.push_back(result);
	}
	if (result.time != 0) {
		result.toString();
		int countDayToBD = result.timeToNow();
		if (countDayToBD == 0) {
			std::cout << "Birthday now!\n";
		}
		else {
			std::cout << "Birthday via " << result.timeToNow() << std::endl;
		}
	}
}