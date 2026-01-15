//#include <utility>

#include "header_modul31.h"

class Toy {
public:
    std::string getName() const {
        return name;
    }

private:
    std::string name;

public:
    Toy(std::string name)
        : name(std::move(name)) {
    }

    ~Toy() {
        std::cout << "Toy " << this->name << " was dropped.\n";
    }
};

class Dog {
    std::string name;
    int age;
    std::shared_ptr<Toy> toy;

public:
    Dog(const std::string &name, const std::shared_ptr<Toy> &toy) {
        Dog(name, 1, toy);
    }

    Dog(const std::string &name, int age, const std::shared_ptr<Toy> &toy)
        : name(name),
          age(age),
          toy(toy) {
    }

    Dog() = default;

    void getToy(const std::shared_ptr<Toy> &newToy) {
        if (newToy == toy) {
            std::cout << "I already have " << newToy->getName() << ".\n";
        } else if (newToy.use_count() > 1) {
            std::cout << "Another dog is playing with " << newToy->getName() << ".\n";
        } else {
            this->toy = newToy;
            std::cout << "I am playing with " << newToy->getName() << ".\n";
        }
    }

    void dropToy() {
        if (toy == nullptr) {
            std::cout << "Nothing to drop.\n";
        } else {
            std::cout << "I dropped " << toy->getName() << ".\n";
            toy.reset();
        }
    }

    ~Dog() = default;
};

void mod31ex1() {
    std::cout << "1. Использование умного указателя.\n";
    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");

    Dog dog1("dog1", 12, ball);
    dog1.dropToy();
    Dog dog2("dog2", 10, ball);
    dog2.dropToy();
    Dog dog3("dog3", 11, ball);
    dog3.dropToy();

    dog1.getToy(ball);
    dog1.getToy(ball);
    dog2.getToy(bone);
    dog3.getToy(ball);

    dog1.dropToy();
    dog1.dropToy();
    dog3.getToy(ball);
}
