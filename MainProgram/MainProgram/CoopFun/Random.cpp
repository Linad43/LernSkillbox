#include "HeaderCoopFun.h"
int random(int min, int max) {
	return (min + rand() % (max - min + 1));
}
float random(float min, float max) {
	return random((int)min, (int)max) + (float)random((int)((min - (int)min) * 1000), (int)((max - (int)max) * 1000)) / 1000;
}