#include "..\header_modul29.h"

/**
 * Тип геометрической фигуры:
 * Круг, Прямоугольник, Треугольник
 */
enum typeShape {
    CIRCLE, RECTANGLE, TRIANGLE
};

/**
 * Класс для описанного прямоугольника
 */
class BoundingBoxDimensions {
public:
    /**
     * Высота
     */
    double height;
    /**
     * Ширина
     */
    double width;

    std::string toString() {
        return "\tBox:\n\t\theight:" + std::to_string(height)
               + "\n\t\twidth: " + std::to_string(width);
    }
};

/**
 * Класс для геометрической фигуры
 */
class Shape {
    /**
     * Тип геометрической фигуры для потомков
     */
    typeShape type;

public:
    /**
     *
     * @return Площадь для геометрической фигуры
     */
    virtual double getArea() = 0;

    /**
     *
     * @return Периметр для геометрической фигуры
     */
    virtual double getPerimeter() = 0;

    /**
     *
     * @return Характеристики описанного прямоугольника
     */
    virtual BoundingBoxDimensions dimensions() = 0;

    /**
     *
     * @return Получить тип фигуры в виде строки
     */
    std::string getType() {
        switch (type) {
            case CIRCLE:
                return "CIRCLE";
            case RECTANGLE:
                return "RECTANGLE";
            case TRIANGLE:
                return "TRIANGLE";
        }
        return "NONE";
    }

    /**
     *
     * @param type Тип фигуры устанавливаемой для классов потомков
     */
    void setType(typeShape type) {
        this->type = type;
    }

    virtual std::string toString() = 0;

    void printParams(Shape *shape) {
        std::cout << "Type: " << shape->getType() << std::endl;
        std::cout << "Square: " << shape->getArea() << std::endl;
        std::cout << "Width: " << shape->dimensions().width << std::endl;
        std::cout << "Height: " << shape->dimensions().height << std::endl;
    }
};

/**
 * Класс круг потомок геометрической фигуры
 */
class Circle : public Shape {
    double radius = 0;

public:
    Circle(double radius) {
        this->setType(typeShape::CIRCLE);
        this->radius = radius;
    }

    double getArea() {
        return PI * pow(radius, 2);
    }

    double getPerimeter() {
        return 2 * PI * radius;
    }

    BoundingBoxDimensions dimensions() {
        BoundingBoxDimensions dim;
        dim.width = this->radius * 2;
        dim.height = this->radius * 2;
        return dim;
    }

    std::string toString() {
        return this->getType() +
               "\n\tradius: " + std::to_string(radius) +
               "\n\tperimeter: " + std::to_string(this->getPerimeter()) +
               "\n\tarea: " + std::to_string(this->getArea()) +
               "\n" + this->dimensions().toString();
    }
};

/**
 * Класс прямоугольник потомок геометрической фигуры
 */
class Rectangle : public Shape {
    double width = 0;
    double height = 0;

public:
    Rectangle(double width, double height) {
        this->setType(typeShape::RECTANGLE);
        this->width = width;
        this->height = height;
    }

    double getArea() {
        return this->width * this->height;
    }

    double getPerimeter() {
        return 2 * this->width + 2 * this->height;
    }

    BoundingBoxDimensions dimensions() {
        BoundingBoxDimensions dim;
        dim.width = this->width;
        dim.height = this->height;
        return dim;
    };

    std::string toString() {
        return this->getType() +
               "\n\twidth: " + std::to_string(this->width) +
               "\n\theight: " + std::to_string(this->height) +
               "\n\tperimeter: " + std::to_string(this->getPerimeter()) +
               "\n\tarea: " + std::to_string(this->getArea()) +
               "\n" + this->dimensions().toString();
    }
};

/**
 * Класс треугольник потомок геометрической фигуры
 */
class Triangle : public Shape {
    double firstSide = 0;
    double secondSide = 0;
    double thirdSide = 0;

public:
    Triangle(double firstSide, double secondSide, double thirdSide) {
        this->setType(typeShape::TRIANGLE);
        this->firstSide = firstSide;
        this->secondSide = secondSide;
        this->thirdSide = thirdSide;
    }

    double getArea() {
        double p = (firstSide + secondSide + thirdSide) / 2;
        return sqrt(p * (p - firstSide) * (p - secondSide) * (p - thirdSide));
    }

    double getPerimeter() {
        return firstSide + secondSide + thirdSide;
    }

    /**
     *
     * @return Описывающий прямоугольник.
     *
     * Построить описывающий прямоугольник,
     * длинная сторона совпадает,
     * а высота рассчитывается от площади.
     */
    BoundingBoxDimensions dimensions() {
        BoundingBoxDimensions dim;
        double maxSide = firstSide;
        if (maxSide < secondSide) maxSide = secondSide;
        if (maxSide < thirdSide) maxSide = thirdSide;
        double height = getArea() * 2 / maxSide;
        dim.width = maxSide;
        dim.height = height;
        return dim;
    }

    std::string toString() {
        return this->getType() +
               "\n\tfirstSide: " + std::to_string(firstSide) +
               "\n\tsecondSide: " + std::to_string(secondSide) +
               "\n\tthirdSide: " + std::to_string(thirdSide) +
               "\n\tarea: " + std::to_string(this->getArea()) +
               "\n\tperimeter: " + std::to_string(this->getPerimeter()) +
               "\n" + this->dimensions().toString();
    }
};

void mod29ex2() {
    std::cout << "2. Интерфейс Shape (дополнительное задание)\n";
    Shape *circle = new Circle(10);
    Shape *rectangle = new class Rectangle(3, 5);
    Shape *triangle = new Triangle(3, 4, 5);
    std::vector<Shape *> shapes = {circle, rectangle, triangle};
    for (auto shape: shapes) {
        std::cout << shape->toString() << std::endl;
    }
    std::cout << std::endl << std::endl;
    for (auto shape: shapes) {
        shape->printParams(shape);
    }
}
