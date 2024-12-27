#include "..\HeaderModul3.h"

void ex3() {
	std::cout << "3. Злостные вредители.\n";
	int speedUp = 50;
	int speedDown = 20;
	float countDay = 2.5;
	float countHight = 2;
	int beginHeight = 100;
	int nowHeight = speedUp * countDay - speedDown * countHight + beginHeight;
	std::cout << "Высота бамбука на третий день " << nowHeight << std::endl;
}