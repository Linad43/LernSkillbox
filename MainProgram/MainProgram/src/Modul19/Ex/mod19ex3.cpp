#include "header_modul19.h"

void mod19ex3() {
	std::cout << "3. Реализовать программу чтения и анализа ведомости с выплатами.\n";
	std::vector <std::string> firstName;
	std::vector <std::string> secondName;
	std::vector <int> pay;
	std::vector <std::string> date;
	std::ifstream file;
	file.open(".\\Modul19\\statement.txt");
	std::string bufString;
	int bufInt, index = 0, maxSum = 0, indexMaxSum = 0, sum = 0;
	while (!file.eof()) {
		file >> bufString;
		firstName.push_back(bufString);
		file >> bufString;
		secondName.push_back(bufString);
		file >> bufInt;
		pay.push_back(bufInt);
		file >> bufString;
		date.push_back(bufString);
		if (maxSum < bufInt) {
			maxSum = bufInt;
			indexMaxSum = index;
		}
		sum += bufInt;
		index++;
	}
	std::cout << "Общее количество выплаченных средств: " << sum << std::endl;
	std::cout << "Человек с максимальной суммой выплат:\n";
	std::cout << firstName[indexMaxSum] << " ";
	std::cout << secondName[indexMaxSum] << " ";
	std::cout << pay[indexMaxSum] << " ";
	std::cout << date[indexMaxSum] << "\n";
}