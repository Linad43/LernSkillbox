﻿#include "..\header_modul3.h"

void mod3ex4() {
	std::cout << "4. Повышаем градус сложности*.\n";
	int a = 42;
	int b = 153;
	std::cout << "a: " << a << "\n"; /* На экран будет выведено 42 */
	std::cout << "b: " << b << "\n"; /* На экран будет выведено 153 */

	/* Меняем значения */
	a = a + b;
	b = a - b;
	a = a - b;

	std::cout << "a: " << a << "\n"; /* На экран будет выведено 153 */
	std::cout << "b: " << b << "\n"; /* На экран будет выведено 42 */
}