#include "header_modul16.h"

enum note {
	DO = 1,
	RE = 2,
	MI = 4,
	FA = 8,
	SOL = 16,
	LA = 32,
	SI = 64
};

void mod16ex4() {
	std::cout << "4. Механическое пианино.\n";
	std::string notes[] = { "DO","RE","MI","FA","SOL","LA","SI" };
	std::cout << "Input chord\n";
	std::string inputChord;
	std::cin >> inputChord;
	int chord = 0;
	for (int i = 0; i < inputChord.size(); i++) {
		int buf = (int)pow(2, inputChord[i] - '1');
		chord = chord | buf;
	}
	
	for (int i = 0; i < 7; i++) {
		if (chord & (int)pow(2, i)) {
			std::cout << notes[i] << " ";
		}
	}
	std::cout << std::endl;
}