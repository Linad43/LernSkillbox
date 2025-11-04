#include "..\header_modul22.h"


std::map<std::string, std::string> manual;

struct numPhone {
	int number[3];

	bool setNums(std::string text) {
		std::vector <int> nums;
		try {
			nums = vectorStrToInt(splitString(text, "-"));
		}
		catch (...) {
			return false;
		}
		if (nums.size() == 3) {
			for (int i = 0; i < 3; i++) {
				number[i] = nums[i];
			}
			return true;
		}
		else {
			//std::cout << "Error input\n";
			return false;
		}
	}

	std::string toString() {
		std::string result;
		for (int i = 0; i < 3; i++) {
			result.append(std::to_string(number[i]));
			if (i != 2) {
				result.append("-");
			}
		}
		return result;
	}
};

bool addToManual(std::string inputText) {
	auto textToManual = splitString(inputText, " ");
	if (textToManual.size() != 2) {
		return false;
	}
	numPhone number;
	if (!number.setNums(textToManual[0])) {
		return false;
	}
	std::string bufNumPhone = textToManual[0];
	std::string name = checkName(textToManual[1]);
	if (name == "") {
		return false;
	}
	else {
		manual[number.toString()] = name;
		return true;
	}
}

std::string getName(std::string inputNumPhone) {
	std::string result;
	numPhone number;
	if (number.setNums(inputNumPhone)) {
		if (manual.find(number.toString()) != manual.end()) {
			result = manual.find(number.toString())->second;
		}
		else {
			result = "Not found";
		}
	}
	return result;
}

std::vector <std::string> getNum(std::string inputName) {
	std::vector <std::string> numbers;
	for (std::map<std::string, std::string>::iterator it = manual.begin(); it != manual.end(); it++) {
		if (it->second == inputName) {
			numbers.push_back(it->first);
		}
	}
	return numbers;
}

void mod22ex1() {
	std::cout << "1. Телефонный справочник.\n";
	std::string input;
	numPhone numbers;
	std::cin.ignore();
	do {
		std::cout << "Input wait\n";
		getline(std::cin, input);
		if (splitString(input, " ").size() == 2) {
			addToManual(input);
		}
		else if (numbers.setNums(input)) {
			auto names = getName(input);
			std::cout << names << std::endl;
		}
		else if (strToLow(input) == "help") {
			std::cout << "\"69-70-30 Ivanov\" - add number phone and name\n";
			std::cout << "\"69-70-30\" - find name by number\n";
			std::cout << "\"Ivanov\" - find num phone by name\n";
			std::cout << "\"help\" - open manual\n";
			std::cout << "\"q\" - exit\n";
		}
		else if (strToLow(input) == "q") {
			break;
		}
		else {
			auto numbers = getNum(input);
			for (int i = 0; (!numbers.empty()) && i < numbers.size(); i++) {
				std::cout << numbers[i] << std::endl;
			}
		}
	} while (true);
}