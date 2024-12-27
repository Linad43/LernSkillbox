#include "HeaderCoopFun.h"
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
	return random((int)min, (int)max) + (float)random((int)((min - (int)min) * 1000), (int)((max - (int)max) * 1000)) / 1000;
}