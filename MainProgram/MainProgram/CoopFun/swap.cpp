#include "header_coop_fun.h"

void swap(int* a, int* b) {
	int buf = *a;
	*a = *b;
	*b = buf;
}