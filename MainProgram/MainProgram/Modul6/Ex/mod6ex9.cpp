#include "..\header_modul6.h"

void reduct(int* a, int* b) {
	int buf = nod(*a, *b);
	*a = *a / buf;
	*b = *b / buf;
}

void sumFract(int aUp, int aDown, int bUp, int bDown, int* resultUp, int* resultDown) {
	*resultDown = nok(aDown, bDown);
	*resultUp = aUp * (nok(aDown, bDown) / aDown) + bUp * (nok(aDown, bDown) / bDown);
}

void diffFract(int aUp, int aDown, int bUp, int bDown, int* resultUp, int* resultDown) {
	sumFract(aUp, aDown, -bUp, bDown, resultUp, resultDown);
}

void mulFract(int aUp, int aDown, int bUp, int bDown, int* resultUp, int* resultDown) {
	*resultUp = aUp * bUp;
	*resultDown = aDown * bDown;
}

void delFract(int aUp, int aDown, int bUp, int bDown, int* resultUp, int* resultDown) {
	mulFract(aUp, aDown, bDown, bUp, resultUp, resultDown);
}

void printFract(int a, int b) {
	printf("%d / %d", a, b);
}

void mod6ex9() {
	std::cout << "9. Калькулятор дробей (Бонус)" << std::endl;

	int aUp, bUp, aDown, bDown, resultUp, resultDown;

	std::cout << "Первая дробь: \n";
	std::cout << "Числитель: ";
	std::cin >> aUp;
	std::cout << "Знаменатель: ";
	std::cin >> aDown;
	printf("%d / %d\n", aUp, aDown);
	reduct(&aUp, &aDown);
	printf("%d / %d\n", aUp, aDown);

	std::cout << "Вторая дробь: \n";
	std::cout << "Числитель: ";
	std::cin >> bUp;
	std::cout << "Знаменатель: ";
	std::cin >> bDown;
	printf("%d / %d\n", bUp, bDown);
	reduct(&bUp, &bDown);
	printf("%d / %d\n", bUp, bDown);

	sumFract(aUp, aDown, bUp, bDown, &resultUp, &resultDown);
	reduct(&resultUp, &resultDown);
	printf("(%d/%d) + (%d/%d) = (%d/%d)\n", aUp, aDown, bUp, bDown, resultUp, resultDown);

	diffFract(aUp, aDown, bUp, bDown, &resultUp, &resultDown);
	reduct(&resultUp, &resultDown);
	printf("(%d/%d) - (%d/%d) = (%d/%d)\n", aUp, aDown, bUp, bDown, resultUp, resultDown);

	mulFract(aUp, aDown, bUp, bDown, &resultUp, &resultDown);
	reduct(&resultUp, &resultDown);
	printf("(%d/%d) * (%d/%d) = (%d/%d)\n", aUp, aDown, bUp, bDown, resultUp, resultDown);

	delFract(aUp, aDown, bUp, bDown, &resultUp, &resultDown);
	reduct(&resultUp, &resultDown);
	printf("(%d/%d) / (%d/%d) = (%d/%d)\n", aUp, aDown, bUp, bDown, resultUp, resultDown);
}
