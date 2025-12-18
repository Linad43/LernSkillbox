#include "..\..\include\header_modul25.h"

//Этот файл лежит в header_coop_fun.h, тут он для быстрого поиска
//Не смог его вывести в отдельный файл, только в заголовок

struct pointTest {
	double x = 0;
	double y = 0;

	void constructor(double inputX, double inputY) {
		x = inputX;
		y = inputY;
	}
	std::string toString() {
		return "(" + std::to_string(x) + ";" + std::to_string(y) + ")";
	}
	double equals(point inputPoint) {
		if (x == inputPoint.x && y == inputPoint.y)
			return true;
		return false;
	}
};