#include "..\header_modul22.h"



void mod22ex3() {
	std::cout << "3. Анаграммы.\n";
	std::vector<std::map <char, int>> word(2);
	std::string inputText;
	std::cin.ignore();
	getline(std::cin, inputText);
	inputText = delSpace(inputText);
	auto buf = splitString(inputText, "-");
	for (int i = 0; i < buf.size(); i++) {
		for (int j = 0; j < buf[i].size(); j++) {
			if (word[i].find(buf[i][j]) != word[i].end()) {
				word[i][buf[i][j]]++;
			}
			else {
				word[i][buf[i][j]] = 1;
			}
		}
	}
	bool check = true;
	if (word[0].size() == word[1].size()) {
		for (std::map <char, int>::iterator it = word[0].begin(); it != word[0].end(); it++) {
			if (!(it->second == word[1][it->first])) {
				check = false;
				break;
			}
		}
	}
	else {
		check = false;
	}
	if (check) {
		std::cout << "This is an annogramma\n";
	}else{
		std::cout << "This is not an annogramma\n";
	}
}