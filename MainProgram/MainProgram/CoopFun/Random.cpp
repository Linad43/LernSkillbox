#include "header_coop_fun.h"
/*
Создание случайного целого числа в пределах от min(включительно) до max(включительно*)
*/
int random(int min, int max) {
	return (min + rand() % (max - min + 1));
}
/*
Создание случайного вещественного числа в пределах от min(включительно) до max(включительно*)
*/
float random(float min, float max) {
	int integer = random((int)min, (int)max - 1);
	float fract = random((int)0, (int)1000) / 1000.0;
	return integer + fract;
}