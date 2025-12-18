#include "..\..\include\header_modul25.h"

std::vector <point> twoPoint() {
	std::vector <point> points;
	std::string input;
	do {
		std::cout << "Input two point (5;8-3;9)\n";
		std::cin >> input;
		auto pointsStr = splitString(input, "-");
		std::vector <double> coordinates;
		for (int i = 0; i < pointsStr.size(); i++) {
			auto buf = splitString(pointsStr[i], ";");
			for (int j = 0; j < buf.size(); j++) {
				coordinates.push_back(stod(buf[j]));
			}
		}
		if (coordinates.size() == 4) {
			point bufPoint;
			bufPoint.constructor(coordinates[0], coordinates[1]);
			points.push_back(bufPoint);
			bufPoint.constructor(coordinates[2], coordinates[3]);
			points.push_back(bufPoint);
			if (!points[0].equals(points[1])) {
				break;
			}
			else {
				std::cout << "Input error. Try again.\n";
			}
		}
		else {
			std::cout << "Input error. Try again.\n";
		}
	} while (true);
	return points;
}
point onePoint() {
	point result;
	std::string input;
	do {
		std::cout << "Input one point (5;8)\n";
		std::cin >> input;
		std::vector <double> coordinates;
		auto buf = splitString(input, ";");
		if (buf.size() == 2) {
			coordinates.push_back(stod(buf[0]));
			coordinates.push_back(stod(buf[1]));
			result.constructor(coordinates[0], coordinates[1]);
			break;
		}
		else {
			std::cout << "Input error. Try again.\n";
		}
	} while (true);
	return result;
}
void scalpel(std::vector <point> vectorPoint) {
	std::cout << "Was made incision " <<
		vectorPoint[0].toString() << " to " <<
		vectorPoint[1].toString() << std::endl;
}

void hemostat(point pointA) {
	std::cout << "Hemostat in " <<
		pointA.toString() << std::endl;
}

void tweezers(point pointA) {
	std::cout << "Tweezers in " <<
		pointA.toString() << std::endl;
}

void suture(std::vector <point> vectorPoint) {
	std::cout << "Was made a seam " <<
		vectorPoint[0].toString() << " to " <<
		vectorPoint[1].toString() << std::endl;
}

void mod25ex1() {
	std::cout << "1. Реализовать симулятор проведения операций.\n";
	std::string input;
	bool incisionDone = false;
	do {
		std::cout << "Input operation:\n";
		std::cin >> input;
		if (input == "scalpel") {
			incisionDone = true;
			scalpel(twoPoint());
		}
		else if (input == "hemostat") {
			if (incisionDone) {
				hemostat(onePoint());
			}
			else {
				std::cout << "Don't hemostat, before scalpel\n";
			}
		}
		else if (input == "tweezers") {
			if (incisionDone) {
				tweezers(onePoint());
			}
			else {
				std::cout << "Don't tweezers, before scalpel\n";
			}
		}
		else if (input == "tweezers") {
			if (incisionDone) {
				tweezers(onePoint());
			}
			else {
				std::cout << "Don't tweezers, before scalpel\n";
			}
		}
		else if (input == "suture") {
			if (incisionDone) {
				suture(twoPoint());
				break;
			}
			else {
				std::cout << "Don't suture, before scalpel\n";
			}
		}
	} while (true);
}