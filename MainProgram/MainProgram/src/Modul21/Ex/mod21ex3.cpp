#include "header_modul21.h"
using namespace std::string_literals;
/*struct point {
	double x = 0.0;
	double y = 0.0;

	void printPoint() {
		std::cout << "[" << x << ";" << y << "]";
	}
	std::string toString() {
		std::string result{ "[" + std::to_string(x) + ";" + std::to_string(y) + "]" };
		//char* result;
		//sprintf(result, "[%f;%f]", x, y);
		return result;
	}
};*/

point add(point A, point B) {
	point result;
	result.x = A.x + B.x;
	result.y = A.y + B.y;
	return result;
}

point subtract(point A, point B) {
	point result;
	result.x = A.x - B.x;
	result.y = A.y - B.y;
	return result;
}

point scale(point A, double b) {
	point result;
	result.x = A.x * b;
	result.y = A.y * b;
	return result;
}

double length(point A) {
	return pow(pow(A.x, 2) + pow(A.y, 2), 0.5);
}

point normalize(point A) {
	point result;
	result.x = A.x / length(A);
	result.y = A.y / length(A);
	return result;
}

void mod21ex3() {
	std::cout << "3. Математический вектор.\n";
	std::string choice;
	do {
		std::cout << "Input next command:\n";
		std::cout << "\"add\" = vector A + vector B\n";
		std::cout << "\"subtract\" = vector A - vector B\n";
		std::cout << "\"scale\" = vector A * b\n";
		std::cout << "\"length\" = |vector A|\n";
		std::cout << "\"normalize\" = vector A / |vector A|\n";
		std::cout << "\"q\" exit\n";
		std::cin >> choice;
		if (choice == "add") {
			point A, B;
			std::cout << "Input vector A:\n";
			std::cout << "A.x:";
			std::cin >> A.x;
			std::cout << "A.y:";
			std::cin >> A.y;
			std::cout << "Input vector B:\n";
			std::cout << "B.x:";
			std::cin >> B.x;
			std::cout << "B.y:";
			std::cin >> B.y;
			std::cout << A.toString() << " + " << B.toString() << " = "
				<< add(A, B).toString() << std::endl;
		}
		else if (choice == "subtract") {
			point A, B;
			std::cout << "Input vector A:\n";
			std::cout << "A.x:";
			std::cin >> A.x;
			std::cout << "A.y:";
			std::cin >> A.y;
			std::cout << "Input vector B:\n";
			std::cout << "B.x:";
			std::cin >> B.x;
			std::cout << "B.y:";
			std::cin >> B.y;
			std::cout << A.toString() << " - " << B.toString() << " = "
				<< subtract(A, B).toString() << std::endl;
		}
		else if (choice == "scale") {
			point A;
			double b;
			std::cout << "Input vector A:\n";
			std::cout << "A.x:";
			std::cin >> A.x;
			std::cout << "A.y:";
			std::cin >> A.y;
			std::cout << "Input b:\n";
			std::cout << "b:";
			std::cin >> b;
			std::cout << A.toString() << " * " << b << " = "
				<< scale(A, b).toString() << std::endl;
		}
		else if (choice == "length") {
			point A;
			std::cout << "Input vector A:\n";
			std::cout << "A.x:";
			std::cin >> A.x;
			std::cout << "A.y:";
			std::cin >> A.y;
			std::cout << "| " << A.toString() << " | = " << length(A) << std::endl;
		}
		else if (choice == "normalize") {
			point A;
			std::cout << "Input vector A:\n";
			std::cout << "A.x:";
			std::cin >> A.x;
			std::cout << "A.y:";
			std::cin >> A.y;
			std::cout << A.toString() << " / | " << A.toString() << " | = "
				<< normalize(A).toString() << std::endl;
		}
		else if (choice == "q") {
			break;
		}
		else {
			continue;
		}
	} while (true);
}