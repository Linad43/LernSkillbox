#include "header_modul13.h"

//std::vector<float> vectorStrToFloat(const std::vector<std::string> &vectorString) {
//	std::vector<float> result(vectorString.size());
//	for (int i = 0; i < vectorString.size(); i++) {
//		result[i] = stof(vectorString[i]);
//	}
//	return result;
//}
//std::vector<int> vectorStrToInt(const std::vector<std::string>& vectorString) {
//	std::vector<int> result(vectorString.size());
//	for (int i = 0; i < vectorString.size(); i++) {
//		result[i] = stoi(vectorString[i]);
//	}
//	return result;
//}

void mod13ex2() {
	std::cout << "2. Exercise 2.\n";
	std::cout << "Input prices: ";
	std::vector<float> prices;
	{
		std::string pricesStr;
		std::cin.ignore();
		getline(std::cin, pricesStr);
		try {
			prices = vectorStrToFloat(splitString(pricesStr, " "));
		}
		catch (...) {
			std::cout << "Incorrect input prices.\n";
		}
	}
	printVector(prices);
	std::cout << "Input items: ";
	std::vector<int> items;
	{
		std::string itemsStr;
		getline(std::cin, itemsStr);
		/*try {
			items = vectorStrToInt(splitString(itemsStr, " "));
		}
		catch(...){
			std::cout << "Incorrect input items.\n";
		}*/
		items = vectorStrToInt(splitString(itemsStr, " "));
		for (auto i{ items.begin() }; i != items.end(); i++) {
			if (*i < 0 || *i >= prices.size()) {
				std::cout << "Incorrect input value items.\n";
				return;
			}
		}
	}
	printVector(items);
	float sum = 0;
	for (auto i{ items.begin() }; i != items.end(); i++) {
		sum += prices[*i];
	}
	std::cout << "Total cost: " << sum << std::endl;
}