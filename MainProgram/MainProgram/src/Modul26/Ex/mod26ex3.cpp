#include "header_modul26.h"

//class Point {
//	int x;
//	int y;
//public:
//	void setX(int pointX) {
//		x = pointX;
//	}
//	void setY(int pointY) {
//		y = pointY;
//	}
//	int getX() {
//		return x;
//	}
//	int getY() {
//		return y;
//	}
//	std::string toString() {
//		return "[" + std::to_string(x) +
//			";" + std::to_string(y) + "]";
//	}
//
//	Point(int x, int y)
//		: x(x), y(y)
//	{
//	}
//};

class Screen {
	int height;
	int width;
public:
	void setHeight(int inputHeight) {
		height = inputHeight;
	}
	void setWidth(int inputWidth) {
		width = inputWidth;
	}
	int getHeight() {
		return height;
	}
	int getWidth() {
		return width;
	}


	Screen(int height, int width)
		: height(height), width(width)
	{
	}
};

class Window {
	Point beginPoint;
	int height;
	int width;
public:
	void setBeginPoint(Point inputBeginPoint) {
		if (inputBeginPoint.getX() >= 0
			&& inputBeginPoint.getY() >= 0) {
			beginPoint = inputBeginPoint;
		}
		else {
			std::cout << "The dot cannot be negative\n";
		}
	}
	Point getBeginPoint() {
		return beginPoint;
	}
	void setHeight(int inputHeight) {
		if (inputHeight >= 0) {
			height = inputHeight;
		}
	}
	void setWidth(int inputWidth) {
		if (inputWidth>=0) {
			width = inputWidth;
		}
	}
	int getHeight() {
		return height;
	}
	int getWidth() {
		return width;
	}
	bool checkInScreen(Screen screen, int inputHeight, int inputWidth) {
		if (beginPoint.getX() + inputWidth>screen.getWidth()) {
			return false;
		}
		if (beginPoint.getY() + inputHeight > screen.getHeight()) {
			return false;
		}
		return true;
	}
	void move(Screen screen, Point inputPoint) {
		beginPoint.setX(beginPoint.getX() + inputPoint.getX());
		beginPoint.setY(beginPoint.getY() + inputPoint.getY());
		if (beginPoint.getX() >= 0 && beginPoint.getY() >= 0
			&& checkInScreen(screen, width, height)) {
			std::cout << "move is done\n";
			std::cout << "new begin point " << beginPoint.toString() << std::endl;
		}
		else {
			beginPoint.setX(beginPoint.getX() - inputPoint.getX());
			beginPoint.setY(beginPoint.getY() - inputPoint.getY());
		}
	}
	void resize(Screen screen, int inputHeight, int inputWidth) {
		if (checkInScreen(screen, inputHeight, inputWidth)) {
			setHeight(inputHeight);
			setWidth(inputWidth);
			std::cout << "resize is done\n";
			std::cout << "new height: " << inputHeight
				<< " new width: " << inputWidth;
		}
	}
	void display(Screen screen) {
		for (int i = 0; i < screen.getWidth(); i++) {
			for (int j = 0; j < screen.getHeight(); j++) {
				if (i >= beginPoint.getY() && i <= beginPoint.getY() + width
					&& j >= beginPoint.getX() && j <= beginPoint.getX() + height) {
					std::cout << "1";
				}
				else {
					std::cout << "0";
				}
			}
			std::cout << std::endl;
		}
	}

	Window(const Point& beginPoint, int height, int width)
		: beginPoint(beginPoint), height(height), width(width)
	{
	}
};

void mod26ex3() {
	std::cout << "3. Реализовать программу управления окном рабочего стола.\n";
	Screen screen = Screen(80, 50);
	Window win = Window(Point(1, 10), 2, 5);
	std::string input;
	while (true) {
		std::cout << "input command:\n";
		std::cin >> input;
		if (input == "move") {
			int x, y;
			std::cout << "input vector for move\nx=";
			std::cin >> x;
			std::cout << "y=";
			std::cin >> y;
			win.move(screen, Point(x, y));
		}
		if (input == "resize") {
			int height, width;
			std::cout << "input new height=";
			std::cin >> height;
			std::cout << "width=";
			std::cin >> width;
			win.resize(screen, height, width);
		}
		if (input == "display") {
			win.display(screen);
		}
		if (input == "close") {
			win.display(screen);
		}
	}
}