#include "header_modul9.h"

void mod9ex3() {
	std::cout << "3. Подсчёт количества слов.\n";
	std::cout << "Введите строку для подсчета" << std::endl;
	
	{//очистка буфера ввода, остальные способы не работают
		std::string buf;
		std::getline(std::cin, buf);
	}

	/*
	char symbol;
	int countWord = 0;
	bool inWord = false;
	while ((symbol = getchar()) != EOF) {
		if (symbol == '\n') {
			break;
		}
		else if (symbol == ' ' || symbol == '\t') {
			inWord = false;
		}
		else if (!inWord) {
			inWord = true;
			countWord++;
		}
	}
	{//очистка буфера ввода, остальные способы не работают
		std::string buf;
		std::getline(std::cin, buf);
	}
	*/
	
	std::string text;
	int countWord = 0;
	bool inWord = false;
	std::getline(std::cin, text);
	
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == '\n') {
			break;
		}
		else if (text[i] == ' ' || text[i] == '\t') {
			inWord = false;
		}
		else if (!inWord) {
			inWord = true;
			countWord++;
		}
	}

	{//очистка буфера ввода, остальные способы не работают
		std::string buf;
		std::getline(std::cin, buf);
	}

	std::cout << "Количество слов " << countWord << std::endl;
}