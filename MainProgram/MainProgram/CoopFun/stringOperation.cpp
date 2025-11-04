#include "header_coop_fun.h"

int lenghtStr(const char* str) {
	int i = 0;
	while (*(str + i) != '\0') {
		i++;
	}
	return i;
}
std::string strToLow(std::string input) {
	std::string result = input;
	for (int i = 0; i < result.size(); i++) {
		result[i] = tolower(result[i]);
	}
	return result;
}
std::string delSpace(std::string text) {
	std::string result;
	auto buf = splitString(text, " ");
	for (int i = 0; i < buf.size(); i++) {
		result += buf[i];
	}
	return result;
}