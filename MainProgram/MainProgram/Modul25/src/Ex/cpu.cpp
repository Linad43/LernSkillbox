#include "..\..\include\header_cpu.h"

void compute() {
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += readOne(i);
	}
}