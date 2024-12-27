#include "header_coop_fun.h"
/*
Расчет НОД
*/
int nod(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a > 0 && b > 0) {
		if (a >= b) a %= b;
		else b %= a;
	}
	return a + b;
}
/*
Расчет НОК
*/
int nok(int a, int b) {
	a = abs(a);
	b = abs(b);
	int result;
	if (a > b) {
		result = a;
		while (result % b != 0) {
			result += a;
		}
	}
	else if (a < b) {
		result = b;
		while (result % a != 0) {
			result += b;
		}
	}
	else {
		return a;
	}
	return result;
}
