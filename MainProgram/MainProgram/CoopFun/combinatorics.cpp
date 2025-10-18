#include "header_coop_fun.h"

int factorial(int a) {
	if (a < 0) {
		return -1;//exeption
	}
	if (a == 1 || a == 0) {
		return 1;
	}
	return a * factorial(a - 1);
}

/*
	Перестановка, то есть, в какое количество последовательностей можно разложить m - вещей взятых из n - вещей
	условие m <= n
	n - кол-во всего вещей
	m - кол-во взятых для комбинаций
	для примера n = 3, m = 2:
	A_m^n=ab,ac,ba,bc,ca,cb=6
*/
int selectOrderNotRepit(int n, int m) {
	if (m > n) {
		return -1;//exeption
	}
	return factorial(n) / factorial(n - m);
}
/*
	Перестановка, то есть, в какое количество последовательностей можно разложить m - вещей взятых из n - вещей
	Возможны повторения
	условие m <= n
	n - кол-во всего вещей
	m - кол-во взятых для комбинаций
	для примера n = 3, m = 2:
	A_m^n=aa,ab,ac,ba,bb,bc,ca,cb,cc=9
*/
int selectOrderRepit(int n, int m) {
	if (m > n) {
		return -1;//exeption
	}
	return pow(n, m);
}
/*
	Выборка, то есть, в какое количество последовательностей можно разложить m - вещей взятых из n - вещей
	порядок не важен в данной перестановке, то есть ab и ba это одна последовательность
	условие m <= n
	n - кол-во всего вещей
	m - кол-во взятых для комбинаций
	для примера n = 3, m = 2:
	A_m^n=ab,ac,bc=3
*/
int selectNotOrderNotRepit(int n, int m) {
	if (m > n) {
		return -1;//exeption
	}
	return factorial(n) / (factorial(m) * factorial(n - m));
}
/*
	Выборка, то есть, в какое количество последовательностей можно разложить m - вещей взятых из n - вещей
	порядок не важен в данной перестановке, то есть ab и ba это одна последовательность.
	Возможны повторения
	условие m <= n
	n - кол-во всего вещей
	m - кол-во взятых для комбинаций
	для примера n = 3, m = 2:
	A_m^n=aa,ab,ac,bb,bc,cc=6
*/
int selectNotOrderRepit(int n, int m) {
	if (m > n) {
		return -1;//exeption
	}
	return factorial(n + m - 1) / (factorial(m) * factorial(n - 1));
}