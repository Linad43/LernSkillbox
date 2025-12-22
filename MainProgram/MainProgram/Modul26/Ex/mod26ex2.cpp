#include "..\header_modul26.h"

enum WhatFind
{
	NUM, NAME, NONE
};

class NumPhone {
	std::string number;
	std::string name;

	NumPhone(std::string inputNumber = "", std::string inputName = "") {
		number = inputNumber;
		name = inputName;
	}

public:

	std::string getNumber() {
		return number;
	}
	std::string getName() {
		return name;
	}

	static NumPhone createNumPhone(std::string inputNumber, std::string inputName) {
		//try {
			setNumber(inputNumber);
			setName(inputName);
			NumPhone numPhone = NumPhone(inputNumber, inputName);
			return numPhone;
		/*}
		catch (const char* error_message) {
			std::cout << "Input error\n";
			std::cout << error_message << std::endl;
		}*/
	}

	static void setNumber(std::string inputNumber) {
		if (isDigit(inputNumber.substr(2, inputNumber.size() - 2), false)
			&& inputNumber.size() == 12
			&& inputNumber.substr(0, 2) == "+7") {
			
		}
		else {
			throw "Number phone uncorrect!\n";
		}
	}

	static void setName(std::string inputName) {
		if (inputName.size() > 2) {
			
		}
		else {
			throw "Name must be longer than 2 characters!\n";
		}
	}
	std::string toString() {
		return "name: " + name 
			+ "\nnum phone: " + number 
			+ "\n";
	}

};

class MobilePhone {
	std::vector <NumPhone> numPhones;
public:
	void add() {
		std::string inputNumber;
		std::string inputName;
		std::cout << "Input name:\n";
		std::cin >> inputName;
		std::cout << "Input number:\n";
		std::cin >> inputNumber;
		try {
			numPhones.push_back(
				NumPhone::createNumPhone(inputNumber, inputName)
			);
			std::cout << "Access add\n";
		}
		catch (const char* error_message) {
			std::cout << "Input error\n";
			std::cout << error_message << std::endl;
		}
		
	}

	std::vector <NumPhone>::iterator findNumPhone(std::string& input)
	{
		auto iteratorFind = numPhones.end();
		if (isDigit(input.substr(2, input.size() - 2))
			&& input.size() == 12
			&& input.substr(0, 2) == "+7") {
			for (auto iter = numPhones.begin(); iter != numPhones.end(); iter++) {
				if (iter->getNumber() == input) {
					iteratorFind = iter;
					break;
				}
			}
		}
		else {
			for (auto iter = numPhones.begin(); iter != numPhones.end(); iter++) {
				if (iter->getName() == input) {
					iteratorFind = iter;
					break;
				}
			}
		}
		return iteratorFind;
	}

	void call() {
		std::cout << "Input number phone or name to call\n";
		std::string input;
		std::cin >> input;
		auto iteratorFind = findNumPhone(input);
		if (iteratorFind == numPhones.end()) {
			std::cout << "Number and name not found!\n";
		}
		else {
			std::cout << "CALL: " << iteratorFind->getNumber() << std::endl;
		}
	}
	void sms() {
		std::string input;
		std::vector <NumPhone>::iterator iteratorFind = numPhones.end();
		while (true) {
			std::cout << "Input number phone or name to sms\n";
			std::cin >> input;
			iteratorFind = findNumPhone(input);
			if (iteratorFind == numPhones.end()) {
				std::cout << "Number and name not found!\n";
				continue;
			}
			std::cout << "Input text your sms\n";
			std::cin >> input;
			break;
		}
		std::cout << "Your text:\n";
		std::cout << input << std::endl;
		std::cout << "Send to " << iteratorFind->getNumber() << std::endl;
	}
};

void mod26ex2() {
	std::cout << "2. Реализовать программу симуляции мобильного телефона.\n";
	std::string input;
	MobilePhone mobilePhone = MobilePhone();
	while (true) {
		std::cout << "Input command:\n";
		std::cin >> input;
		if (input == "add") {
			mobilePhone.add();
		}
		if (input == "call") {
			mobilePhone.call();
		}
		if (input == "sms") {
			mobilePhone.sms();
		}
		if (input == "exit") {
			break;
		}
	}
}