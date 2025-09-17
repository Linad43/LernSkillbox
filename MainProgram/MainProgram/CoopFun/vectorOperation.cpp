#include "header_coop_fun.h"

void printVector(const std::vector<int>& numbers) {
	for (auto i{ numbers.begin() }; i != numbers.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void printVector(const std::vector<float>& numbers) {
	for (auto i{ numbers.begin() }; i != numbers.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void printVector(const std::vector<std::string>& numbers) {
	for (auto i{ numbers.begin() }; i != numbers.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

std::vector<float> vectorStrToFloat(const std::vector<std::string>& vectorString) {
	std::vector<float> result(vectorString.size());
	for (int i = 0; i < vectorString.size(); i++) {
		result[i] = stof(vectorString[i]);
	}
	return result;
}

std::vector<int> vectorStrToInt(const std::vector<std::string>& vectorString) {
	std::vector<int> result(vectorString.size());
	for (int i = 0; i < vectorString.size(); i++) {
		result[i] = stoi(vectorString[i]);
	}
	return result;
}