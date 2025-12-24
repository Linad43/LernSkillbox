#include "..\header_modul27.h"

class Figure {
	double perimeter;
	double area;
	Point* center;
public:
	double getPerimeter() {
		return perimeter;
	}
	double getArea() {
		return area;
	}
	Point* getCenter() {
		return center;
	}
	void setPerimeter(double perimeter) {
		if (perimeter > 0) {
			this->perimeter = round(perimeter * 100) / 100;
			std::cout << "Perimeter: " << this->perimeter << std::endl;
		}
		else {
			std::cout << "Set perimeter error\n";
		}
	}
	void setArea(double area) {
		if (area > 0) {
			this->area = round(area * 100) / 100;
			std::cout << "Area: " << this->area << std::endl;
		}
		else {
			std::cout << "Set area error\n";
		}
	}
	void setCenter(Point* center) {
		this->center = center;
	}

	Figure() = default;

};


class Square :public Figure {
	double sizeEdge;
	Square() = default;
public:
	double getSizeEdge() {
		return sizeEdge;
	}
	void calkPerimeter() {
		setPerimeter(4 * sizeEdge);
	}
	void calkArea() {
		setArea(pow(sizeEdge, 2));
	}
	void setSizeEdge(double sizeEdge) {
		if (sizeEdge > 0) {
			this->sizeEdge = sizeEdge;
			std::cout << "Size edge: " << this->sizeEdge << std::endl;
		}
		else {
			std::cout << "Set radius error\n";
		}
	}

	static Square createSquare() {
		std::cout << "Input the center point of the square A[x;y]\nx = ";
		double x, y, sizeEdge = 0;
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Point* center = new Point(x, y);
		while (sizeEdge <= 0) {
			std::cout << "Input size edge square\n";
			std::cin >> sizeEdge;
			if (sizeEdge <= 0) {
				std::cout << "Size edge must been more zero\nTry again\n";
			}
		}
		Square square = Square();
		square.setCenter(center);
		square.setSizeEdge(sizeEdge);
		square.calkArea();
		square.calkPerimeter();

		std::cout << "Square out, center in " << center->toString() << std::endl;
		Square squareOut = Square(sizeEdge + 1, center);
		squareOut.calkArea();
		squareOut.calkPerimeter();

		delete center;
		return square;
	}

	Square(double sizeEdge, Point* center)
		: sizeEdge(sizeEdge)
	{
		setCenter(center);
	}
};

class Circle :public Figure {
	double radius;
	Circle() = default;
public:

	double getRadius() {
		return radius;
	}
	void setRadius(double radius) {
		if (radius > 0) {
			this->radius = radius;
			std::cout << "Radius: " << this->radius << std::endl;
		}
		else {
			std::cout << "Set radius error\n";
		}
	}
	void calkPerimeter() {
		setPerimeter(2 * PI * radius);
	}
	void calkArea() {
		std::cout << "pi = " << PI << std::endl;
		setArea(PI * pow(radius, 2));
	}
	static Circle createCircle() {
		std::cout << "Input the center point of the circle A[x;y]\nx = ";
		double x, y, radius = 0;
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Point* center = new Point(x, y);
		while (radius <= 0) {
			std::cout << "Input radius circle\n";
			std::cin >> radius;
			if (radius <= 0) {
				std::cout << "Radius must been more zero\nTry again\n";
			}
		}
		Circle circle = Circle();
		circle.setCenter(center);
		circle.setRadius(radius);
		circle.calkArea();
		circle.calkPerimeter();

		std::cout << "Square out, center in " << center->toString() << std::endl;
		Square square = Square(radius * 2, center);
		square.calkArea();
		square.calkPerimeter();

		delete center;
		return circle;
	}
};

class EqTriangle :public Figure {
	double sizeEdge;
	EqTriangle() = default;
public:
	double getSizeEdge() {
		return sizeEdge;
	}
	void calkPerimeter() {
		setPerimeter(3 * sizeEdge);
	}
	void calkArea() {
		setArea((sqrt(3) * pow(sizeEdge, 2)) / 4);
	}
	void setSizeEdge(double sizeEdge) {
		if (sizeEdge > 0) {
			this->sizeEdge = sizeEdge;
			std::cout << "Size edge: " << this->sizeEdge << std::endl;
		}
		else {
			std::cout << "Set radius error\n";
		}
	}
	static EqTriangle createEqTriangle() {
		std::cout << "Input the center point of the equilateral triangle A[x;y]\nx = ";
		double x, y, sizeEdge = 0;
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Point* center = new Point(x, y);
		while (sizeEdge <= 0) {
			std::cout << "Input size edge equilateral triangle\n";
			std::cin >> sizeEdge;
			if (sizeEdge <= 0) {
				std::cout << "Size edge must been more zero\nTry again\n";
			}
		}
		EqTriangle eqTriangle = EqTriangle();
		eqTriangle.setCenter(center);
		eqTriangle.setSizeEdge(sizeEdge);
		eqTriangle.calkArea();
		eqTriangle.calkPerimeter();

		double radOutCircle = sizeEdge / (sqrt(3));
		
		std::cout << "Square out, center in " << center->toString() << std::endl;
		Square square = Square(radOutCircle * 2, center);
		square.calkArea();
		square.calkPerimeter();

		delete center;
		return eqTriangle;
	}
};

class Rectangle :public Figure {
	double sizeEdgeFirst;
	double sizeEdgeSecond;
	Rectangle() = default;
public:
	double getSizeEdgeFirst() {
		return sizeEdgeFirst;
	}
	double getSizeEdgeSecond() {
		return sizeEdgeSecond;
	}
	void calkPerimeter() {
		setPerimeter((sizeEdgeFirst + sizeEdgeSecond) * 2);
	}
	void calkArea() {
		setArea(sizeEdgeFirst * sizeEdgeSecond);
	}
	void setSizeEdgeFirst(double sizeEdge) {
		if (sizeEdge > 0) {
			sizeEdgeFirst = sizeEdge;
			std::cout << "Size edge: " << sizeEdgeFirst << std::endl;
		}
		else {
			std::cout << "Set edge error\n";
		}
	}
	void setSizeEdgeSecond(double sizeEdge) {
		if (sizeEdge > 0) {
			sizeEdgeSecond = sizeEdge;
			std::cout << "Size edge: " << sizeEdgeSecond << std::endl;
		}
		else {
			std::cout << "Set edge error\n";
		}
	}
	static Rectangle createRectangle() {
		std::cout << "Input the center point of the rectangle A[x;y]\nx = ";
		double x, y, sizeEdgeFirst = 0, sizeEdgeSecond = 0;
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Point* center = new Point(x, y);
		while (sizeEdgeFirst <= 0) {
			std::cout << "Input size first edge rectangle\n";
			std::cin >> sizeEdgeFirst;
			if (sizeEdgeFirst <= 0) {
				std::cout << "Size edge must been more zero\nTry again\n";
			}
		}
		while (sizeEdgeSecond <= 0) {
			std::cout << "Input size second edge rectangle\n";
			std::cin >> sizeEdgeSecond;
			if (sizeEdgeSecond <= 0) {
				std::cout << "Size edge must been more zero\nTry again\n";
			}
		}
		Rectangle rectangle = Rectangle();
		rectangle.setCenter(center);
		rectangle.setSizeEdgeFirst(sizeEdgeFirst);
		rectangle.setSizeEdgeSecond(sizeEdgeSecond);
		rectangle.calkArea();
		rectangle.calkPerimeter();

		std::cout << "Rectangle out, center in " << center->toString() << std::endl;
		Rectangle rectangleOut = Rectangle((sizeEdgeFirst + 1),
			(sizeEdgeSecond + 1),
			center);
		rectangleOut.calkArea();
		rectangleOut.calkPerimeter();

		delete center;
		return rectangle;
	}


	Rectangle(double sizeEdgeFirst, double sizeEdgeSecond, Point* center)
		: sizeEdgeFirst(sizeEdgeFirst), sizeEdgeSecond(sizeEdgeSecond)
	{
		setCenter(center);
	}
};

void mod27ex1() {
	std::cout << "1. Иерархия геометрических фигур.\n";
	std::string input;
	while (true) {
		std::cout << "Input command\n";
		std::cin >> input;
		if (input == "circle") {
			Circle::createCircle();
		}
		else if (input == "square") {
			Square::createSquare();
		}
		else if (input == "triangle") {
			EqTriangle::createEqTriangle();
		}
		else if (input == "rectangle") {
			Rectangle::createRectangle();
		}
		else if (input == "exit") {
			break;
		}
	}
}