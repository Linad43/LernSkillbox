#include "header_coop_fun.h"

int fibonacci(int num) {
	if (num == 1 || num == 2) {
		return 1;
	}
	else {
		int first, second, buf = 0;
		first = second = 1;
		int i = 2;
		while (i++ < num) {
			buf = first + second;
			first = second;
			second = buf;
		}
		return buf;
	}
}