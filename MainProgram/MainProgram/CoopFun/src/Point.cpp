#include "../include/header_coop_fun.h"

void Point::setX(double pointX) {
    x = pointX;
}

void Point::setY(double pointY) {
    y = pointY;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

std::string Point::toString() {
    return "[" + std::to_string(x) +
           ";" + std::to_string(y) + "]";
}

Point::Point(double x, double y)
    : x(x), y(y) {
}
