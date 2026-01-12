#include "header_modul22.h"

bool annogram(std::string first, std::string second) {
	std::map <char, int> word;
	for (int j = 0; j < first.size(); j++) {
		if (word.find(first[j]) != word.end()) {
			word[first[j]]++;
		}
		else {
			word[first[j]] = 1;
		}
	}
	for (int j = 0; j < second.size(); j++) {
		if (word.find(second[j]) != word.end() && word[second[j]] > 0) {
			word[second[j]]--;
			if (word[second[j]] == 0) {
				word.erase(second[j]);
			}
		}
		else {
			return false;
		}
	}
	return word.empty();
}

void mod22ex3() {
	std::cout << "3. Анаграммы.\n";
	std::vector<std::map <char, int>> word(2);
	std::string inputText;
	std::cin.ignore();
	getline(std::cin, inputText);
	inputText = delSpace(inputText);
	auto buf = splitString(inputText, "-");

	if (annogram(buf[0], buf[1])) {
		std::cout << "This is an annogramma\n";
	}
	else {
		std::cout << "This is not an annogramma\n";
	}
}