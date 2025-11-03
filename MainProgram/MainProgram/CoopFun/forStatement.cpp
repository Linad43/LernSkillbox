#include "header_coop_fun.h"


int getCurrentYear() {
	std::time_t t = std::time(nullptr);
	std::tm* const pTInfo = std::localtime(&t);
	return 1900 + pTInfo->tm_year;
}

bool lackNum(std::string text) {
	for (int i = 0; i < text.size(); i++) {
		if ((text[i] < 'A' || text[i] > 'Z') &&
			(text[i] < 'a' || text[i] > 'z')) {
			return false;
		}
	}
	return true;
}

std::string checkName(std::string input) {
	std::string result = "";
	if (input.size() > 2 && lackNum(input)){
		result = input;
	}
	return result;
}

std::string checkDate(std::string input) {
	std::string result = "";
	if (input.size() == 10) {
		std::vector <std::string> date = splitString(input, ".");
		if ((stoi(date[0]) > 0 && stoi(date[0]) < 31) && 
			(stoi(date[1]) > 0 && stoi(date[1])<=12) &&
			(stoi(date[2]) > 1900 && stoi(date[2]) <= getCurrentYear())) {
			result = input;
		}
	}
	return result;
}

int checkPayment(std::string input) {
	int result;
	try {
		result = stoi(input);
	}
	catch (...) {
		result = -1;
	}
	if (result < 0) {
		result = -1;
	}
	for (int i = 0; i < input.size(); i++) {
		if (input[i] < '0' || input[i]>'9') {
			result = -1;
			break;
		}
	}
	return result;
}
