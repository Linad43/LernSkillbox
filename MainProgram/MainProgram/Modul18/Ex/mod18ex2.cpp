#include "..\header_modul18.h"

std::vector <std::vector <int>> mainVec;

int sum(std::vector <int> vec) {
	int result = 0;
	for (int i = 0; i < vec.size(); result += vec[i++]);
	return result;
}

void nextVector(std::vector <int>& vec, int k) {
	vec[vec.size() - 1]++;
	for (int i = vec.size() - 1; i >= 0; i--) {
		if (vec[i] > k) {
			vec[i] = 1;
			vec[i - 1]++;
		}
		else {
			break;
		}
	}
	//printVector(vec);
}

int jump(int n, int k = 3) {
	int count = 0;
	if (k == 0) {
		return -1;
	}
	for (int sizeVec = n; sizeVec >= n / k; sizeVec--) {
		std::vector <int> bufVec(sizeVec, 1);
		bufVec[bufVec.size() - 1] = 0;
		for (int i = 0; i < pow(k, sizeVec); ++i) {
			nextVector(bufVec, k);
			//printVector(bufVec);
			if (sum(bufVec) == n) {
				mainVec.push_back(bufVec);
				std::cout << ++count << "===";
				printVector(bufVec);
			}

		}
	}
	return count;
}

void mod18ex2() {
	std::cout << "2. Задача 2.\n";
	std::cout << jump(9, 3) << std::endl;
}