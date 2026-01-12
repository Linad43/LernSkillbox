#include "header_modul16.h"

void mod16ex3() {
	std::cout << "3. Калькулятор.\n";
	std::cout << "Введите выражение:\n";
	std::string inputText;
	std::cin >> inputText;
	std::string dels[] = {"+","-","*","/"};
	int i = 0;
	while (splitString(inputText, dels[i]).size() < 2) {
		i++;
	}
	std::vector <std::string> nums_str = splitString(inputText, dels[i]);
	double result=stod(nums_str[0]);
	if (dels[i] == "+") {
		result += stod(nums_str[1]);
	}else if (dels[i] == "-") {
		result -= stod(nums_str[1]);
	}else if (dels[i] == "*") {
		result *= stod(nums_str[1]);
	}else if (dels[i] == "/") {
		result /= stod(nums_str[1]);
	}
	std::cout << inputText << "=" << result << std::endl;
}