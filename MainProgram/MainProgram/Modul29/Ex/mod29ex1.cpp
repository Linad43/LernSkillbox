#include "..\header_modul29.h"

class Talent {
public:
    virtual void whatICan() = 0;
};

class Swimming : public Talent {
public:
    void whatICan() {
        std::cout << "Swim";
    }
};

class Dancing : public Talent {
public:
    void whatICan() {
        std::cout << "Dancing";
    }
};

class Counting : public Talent {
public:
    void whatICan() {
        std::cout << "Counting";
    }
};

class Animal {
protected:
    std::string name = "animal";
    std::vector<Talent *> talents;
    int age = 0;

public:
    virtual void voice() = 0;

    virtual void addTalent(Talent *talent) {
        talents.push_back(talent);
    }

    virtual void showTalents() {
        std::cout << "This is ";
        std::cout << name;
        std::cout << " and it has some talents:" << std::endl;
        for (auto talent: talents) {
            std::cout << "It can \"";
            talent->whatICan();
            std::cout << "\"" << std::endl;
        }
    }
};

class Dog : public Animal {
public:
    Dog() = default;

    Dog(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    virtual void voice() {
        std::cout << "Bark!" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat() = default;

    Cat(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    virtual void voice() {
        std::cout << "Meow!" << std::endl;
    }
};

void mod29ex1() {
    std::cout << "1. Задача 1. Суперпёс.\n";
    Animal *c = new Cat();
    Animal *d = new Dog();
    Talent *swim = new Swimming();
    Talent *dance = new Dancing();
    d->addTalent(dance);
    d->addTalent(swim);
    d->showTalents();
}
