#include "header_coop_fun.h"

int lenght(const char* str) {
	int i = 0;
	while (*(str + i) != '\0') {
		i++;
	}
	return i;
}