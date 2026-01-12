#include "header_modul20.h"
//
//int getCurrentYear() {
//	std::time_t t = std::time(nullptr);
//	std::tm* const pTInfo = std::localtime(&t);
//	return 1900 + pTInfo->tm_year;
//}
//
struct stateElement {
	std::string firstName;
	std::string lastName;
	int pay=0;
	std::string date;
};
//
//bool lackNum(std::string text) {
//	for (int i = 0; i < text.size(); i++) {
//		if ((text[i] < 'A' || text[i] > 'Z') &&
//			(text[i] < 'a' || text[i] > 'z')) {
//			return false;
//		}
//	}
//	return true;
//}
//
//std::string checkName(std::string input) {
//	std::string result = "";
//	if (input.size() > 2 && lackNum(input)){
//		result = input;
//	}
//	return result;
//}
//
//std::string checkDate(std::string input) {
//	std::string result = "";
//	if (input.size() == 10) {
//		std::vector <std::string> date = splitString(input, ".");
//		if ((stoi(date[0]) > 0 && stoi(date[0]) < 31) && 
//			(stoi(date[1]) > 0 && stoi(date[1])<=12) &&
//			(stoi(date[2]) > 1900 && stoi(date[2]) <= getCurrentYear())) {
//			result = input;
//		}
//	}
//	return result;
//}
//
//int checkPayment(std::string input) {
//	int result;
//	try {
//		result = stoi(input);
//	}
//	catch (...) {
//		result = -1;
//	}
//	if (result < 0) {
//		result = -1;
//	}
//	for (int i = 0; i < input.size(); i++) {
//		if (input[i] < '0' || input[i]>'9') {
//			result = -1;
//			break;
//		}
//	}
//	return result;
//}

void mod20ex1() {
	std::cout << "1. Запись в ведомость учёта.\n";
	stateElement element;
	std::string buf;
	do {
		std::cout << "Input first name: ";
		std::cin >> buf;
		element.firstName = checkName(buf);
		if (element.firstName == "") {
			std::cout << "Input uncorrect name.\n";
			std::cout << "Name must have more than one charecter and not contain numbers.\n";
		}
		else {
			break;
		}
	} while (true);
	do {
		std::cout << "Input last name: ";
		std::cin >> buf;
		element.lastName = checkName(buf);
		if (element.lastName == "") {
			std::cout << "Input uncorrect name.\n";
			std::cout << "Name must have more than one charecter and not contain numbers.\n";
		}
		else {
			break;
		}
	} while (true);
	do {
		std::cout << "Input date of issue(DD.MM.YYYY): ";
		std::cin >> buf;
		element.date = checkDate(buf);
		if (element.date == "") {
			std::cout << "Input uncorrect date.\n";
			std::cout << "Try again.\n";
		}
		else {
			break;
		}
	} while (true);
	do{
		std::cout << "Input sum of payment: ";
		std::cin >> buf;
		element.pay = checkPayment(buf);
		if (element.pay < 0) {
			std::cout << "Input uncorrect date.\n";
			std::cout << "Payment must have more than zero and not contain letters.\n";
		}
		else {
			break;
		}
	} while (true);
	std::string nameFile = ".\\Modul20\\statement.txt";
	std::ofstream file(nameFile, std::ios::app);
	//file.open(nameFile, std::ios::app);
	file << element.firstName << " ";
	file << element.lastName << " ";
	file << element.pay << " ";
	file << element.date << "\n";
	file.close();
}