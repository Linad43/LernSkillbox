//#include "..\HeaderModul3.h"
#include "..\..\HeaderMain.h"

void mod3ex2() {
	std::cout << "2. Обмен местами.\n";
	int a = 42;
	int b = 153;
	std::cout << "a: " << a << "\n"; /* На экран будет выведено 42 */
	std::cout << "b: " << b << "\n"; /* На экран будет выведено 153 */

	/* Меняем значения */
	int buf = a;
	a = b;
	b = buf;

	std::cout << "a: " << a << "\n"; /* На экран будет выведено 153 */
	std::cout << "b: " << b << "\n"; /* На экран будет выведено 42 */

}