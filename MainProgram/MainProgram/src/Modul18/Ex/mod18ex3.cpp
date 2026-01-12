#include "header_modul18.h"

void evendigits(long long n, int& ans) {
	while (n > 0) {
		if (n % 2 == 0) {
			ans++;
		}
		n /= 10;
	}
}

void mod18ex3() {
	std::cout << "3. Задача 3.\n";
	int ans = 0;
	evendigits(9223372036854775806, ans);
	//ans == 10
	std::cout << ans << std::endl;
}