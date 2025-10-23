#include "..\header_modul20.h"
#define COUNT_TOTAL 1

//Не могу найти ошибку,
//при чтении последний символ добавляется в самый конец файла
//в mod20ex3 такая же ошибка не найду причины

struct stateATM {
	int o = 0;
	int t = 0;
	int f = 0;
	int O = 0;
	int T = 0;
	int F = 0;

	int sumCout() {
		return o + t + f + O + T + F;
	}
	int sum() {
		return F * 5000 + T * 2000 + O * 1000 + f * 500 + t * 200 + o * 100;
	}
	void toString() {
		std::cout << "In stock:\n";
		std::cout << "5000 (" << F << ")\n";
		std::cout << "2000 (" << T << ")\n";
		std::cout << "1000 (" << O << ")\n";
		std::cout << "500 (" << f << ")\n";
		std::cout << "200 (" << t << ")\n";
		std::cout << "100 (" << o << ")\n";
		std::cout << "Sum = " << sum() << std::endl;
	}
};

stateATM nowStateATM;

void fullATM() {
	int buf;
	for (int i = nowStateATM.sumCout(); i < COUNT_TOTAL; i++) {
		buf = rand() % 6;
		switch (buf)
		{
		case 0: {
			nowStateATM.o++;
			break;
		}
		case 1: {
			nowStateATM.t++;
			break;
		}
		case 2: {
			nowStateATM.f++;
			break;
		}
		case 3: {
			nowStateATM.O++;
			break;
		}
		case 4: {
			nowStateATM.T++;
			break;
		}
		case 5: {
			nowStateATM.F++;
			break;
		}
		default:
			break;
		}
	}
}

void readFile() {
	const char* nameFile = ".\\Modul20\\ATP.bin";
	std::ifstream file(nameFile, std::ios::binary);
	char buf;
	if (file.is_open()) {
		while (!file.eof()) {
			file.read(&buf, sizeof(buf));
			switch (buf)
			{
			case 'o': {
				nowStateATM.o++;
				break;
			}
			case 't': {
				nowStateATM.t++;
				break;
			}
			case 'f': {
				nowStateATM.f++;
				break;
			}
			case 'O': {
				nowStateATM.O++;
				break;
			}
			case 'T': {
				nowStateATM.T++;
				break;
			}
			case 'F': {
				nowStateATM.F++;
				break;
			}
			default:
				break;
			}
		}
	}
	file.close();
	remove(nameFile);
}

void writeFile() {
	const char* nameFile = ".\\Modul20\\ATP.bin";
	std::ofstream file(nameFile, std::ios::binary | std::ios::out);
	char buf = 'o';
	int* bufATM = &(nowStateATM.o);
	int index = 0;
	bool flag = true;
	while (flag) {
		while (*bufATM != 0) {
			file.write(&buf, sizeof(char));
			(*bufATM)--;
		}
		index++;
		switch (index)
		{
		case 1: {
			buf = 't';
			bufATM = &nowStateATM.t;
			break;
		}
		case 2: {
			buf = 'f';
			bufATM = &nowStateATM.f;
			break;
		}
		case 3: {
			buf = 'O';
			bufATM = &nowStateATM.O;
			break;
		}
		case 4: {
			buf = 'T';
			bufATM = &nowStateATM.T;
			break;
		}
		case 5: {
			buf = 'F';
			bufATM = &nowStateATM.F;
			break;
		}
		default:
			flag = false;
			break;
		}
	}
	file.close();
}

void getCash(int sum) {
	int buf = sum;
	int need_F = buf / 5000;
	buf %= 5000;
	int need_T = buf / 2000;
	buf %= 2000;
	int need_O = buf / 1000;
	buf %= 1000;
	int need_f = buf / 500;
	buf %= 500;
	int need_t = buf / 200;
	buf %= 200;
	int need_o = buf / 100;
	buf %= 100;

	if (buf != 0) {
		std::cout << "Do't get cash. Out of stock money.";
		return;
	}

	if (nowStateATM.F < need_F) {
		need_T += 2 * (need_F - nowStateATM.F);
		need_O += need_F - nowStateATM.F;
		need_F = nowStateATM.F;
	}
	if (nowStateATM.T < need_T) {
		need_O += 2 * (need_T - nowStateATM.T);
		need_T = nowStateATM.T;
	}
	if (nowStateATM.O < need_O) {
		need_f += 2 * (need_O - nowStateATM.O);
		need_O = nowStateATM.O;
	}
	if (nowStateATM.f < need_f) {
		need_f += 2 * (need_f - nowStateATM.f);
		need_o += need_f - nowStateATM.f;
		need_f = nowStateATM.f;
	}
	if (nowStateATM.t < need_t) {
		need_o += 2 * (need_t - nowStateATM.t);
		need_t = nowStateATM.t;
	}
	if (nowStateATM.o < need_o) {
		std::cout << "Do't get cash. Out of stock money.";
		return;
	}

	nowStateATM.F -= need_F;
	nowStateATM.T -= need_T;
	nowStateATM.O -= need_O;
	nowStateATM.f -= need_f;
	nowStateATM.t -= need_t;
	nowStateATM.o -= need_o;

	std::cout << "You get:\n";
	std::cout << "5000 x " << need_F << " = " << need_F * 5000 << std::endl;
	std::cout << "2000 x " << need_T << " = " << need_T * 2000 << std::endl;
	std::cout << "1000 x " << need_O << " = " << need_O * 1000 << std::endl;
	std::cout << "500 x " << need_f << " = " << need_f * 500 << std::endl;
	std::cout << "200 x " << need_t << " = " << need_t * 200 << std::endl;
	std::cout << "100 x " << need_o << " = " << need_o * 100 << std::endl;
	std::cout << "Sum: " << need_F * 5000 + need_T * 2000 + need_O * 1000 +
		need_f * 500 + need_t * 200 + need_o * 100;
	std::cout << std::endl;
}

void mod20ex4() {
	std::cout << "4. Симуляция работы банкомата.\n";
	readFile();
	char choise;
	bool flag = true;
	do {
		nowStateATM.toString();
		std::cout << "+ ... Full ATM\n";
		std::cout << "- ... Get cash\n";
		std::cout << "Q ... Exit\n";
		std::cin >> choise;
		switch (choise)
		{
		case '+': {
			fullATM();
			break;
		}
		case '-': {
			std::cout << "Input sum receive cash:\n";
			int cash;
			std::cin >> cash;
			getCash(cash);
			break;
		}
		case 'q':
		case 'Q': {
			flag = false;
			writeFile();
			break;
		}
		default:
			break;
		}
	} while (flag);
}