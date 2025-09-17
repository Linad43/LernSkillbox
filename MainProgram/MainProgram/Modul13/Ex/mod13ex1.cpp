#include "..\header_modul13.h"

//std::vector<int> vectorStrToInt(const std::vector<std::string>& vectorString) {
//	std::vector<int> result(vectorString.size());
//	for (int i = 0; i < vectorString.size(); i++) {
//		result[i] = stoi(vectorString[i]);
//	}
//	return result;
//}

std::vector<int> delNum(const std::vector<int>& numbers, int removeNum) {
	std::vector<int> result = numbers;
	int countRemove = 0;
	int i = 0;
	while (i < result.size() - countRemove) {
		if (result[i] == removeNum) {
			result.erase(result.begin() + i);
			countRemove++;
		}
		else
		{
			i++;
		}
	}
	return result;
}

//void printVector(const std::vector<int>& numbers) {
//	for (auto i{ numbers.begin() }; i != numbers.end(); i++) {
//		std::cout << *i << " ";
//	}
//	std::cout << std::endl;
//}

void mod13ex1() {
	std::cout << "1. Exercise 1.\n";
	int vectorSize = 0;
	std::vector<int> numbers(vectorSize);
	std::cout << "Input vector size: ";
	std::cin >> vectorSize;
	numbers.resize(vectorSize);
	std::cout << "Input numbers: ";
	std::string inputText;
	std::cin.ignore();
	getline(std::cin, inputText);
	try
	{
		numbers = vectorStrToInt(splitString(inputText, " "));
	}
	catch (...)
	{
		std::cout << "Incorrect input. Enter integer numbers separated by spaces.\n";
		return;
	}
	if (vectorSize != numbers.size()) {
		std::cout << "Incorrect size. \"Vector size\" doesn't match to vector size \"numbers\".\n";
		return;
	}
	std::cout << "Input number to delete: ";
	int removeNum;
	std::cin >> removeNum;
	numbers = delNum(numbers, removeNum);
	std::cout << "Result: ";
	printVector(numbers);
}