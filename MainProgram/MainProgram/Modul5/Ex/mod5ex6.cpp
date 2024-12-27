#include "..\HeaderModul5.h"

void mod5ex6() {
	std::cout << "6. Грустное совершеннолетие" << std::endl;
	std::cout << "Введите дату рождения(гггг.мм.дд)" << std::endl;
	int personYear, personMounth, personDay;
	/*Есть способ сделать форматированный ввод помимо "scanf_s"?
	Я смог придумать
	cin >> year >> mounth >> day
	Но в таком случае нужно вводить данные через пробел
	а что бы вводить через точку, нужно только создавать строку, и разделять строку через точки?*/
	scanf_s("%d.%d.%d", &personYear, &personMounth, &personDay);
	std::cout << "Введите сегодняшнюю дату(гггг.мм.дд)" << std::endl;
	int nowYear, nowMounth, nowDay;
	scanf_s("%d.%d.%d", &nowYear, &nowMounth, &nowDay);
	bool flag = 0;
	if (nowYear - personYear > 18) {
		flag = 1;
	}
	else if (nowYear - personYear == 18) {
		if (nowMounth - personMounth > 0) {
			flag = 1;
		}
		else if (nowMounth - personMounth == 0) {
			if (nowDay - personDay > 0) {
				flag = 1;
			}
		}
	}
	if (flag) {
		std::cout << "Продавать алкоголь можно" << std::endl;
	}
	else {
		std::cout << "Продавать алкоголь НЕЛЬЗЯ!" << std::endl;
	}
}