#include "header_modul15.h"
#define SIZE_DATA 9

void mod15ex1() {
	std::cout << "1. Exercise 1.\n";
	int inputData[] = { -2,1,-3,4,-1,2,1,-5,4 };
	int sumBuf, beg, end, sum=inputData[0];
	for (int i(0); i < SIZE_DATA; i++) {
		sumBuf = 0;
		for (int j(i); j < SIZE_DATA; j++) {
			sumBuf += inputData[j];
			if (sumBuf > sum) {
				sum = sumBuf;
				beg = i;
				end = j;
			}
		}
	}
	std::cout << beg << " and " << end << std::endl;
}