#include "header_modul31.h"

// Класс игрушки
class Toy {
    std::string name;

public:
    explicit Toy(const std::string &name) {
        this->name = name;
    }

    const std::string &getName() const { return name; }

    //Деструктор, для отображения надписи
    ~Toy() {
        std::cout << "Toy " << name << " was dropped.\n";
    }
};

// Управление объектами типа Toy
class shared_ptr_toy {
    //Наш объект
    Toy *obj;
    //Кол-во объектов с таким указателем
    //Необходимо передавать ссылку иначе некорректно выведет
    int *count;

public:
    // Конструктор по умолчанию
    shared_ptr_toy() noexcept = default;

    // Конструктор с передачей объекта
    shared_ptr_toy(Toy *oth) {
        //Сам объект
        obj = oth;
        //Подсчет объектов
        count = new int(1);
    }

    // Копирующий конструктор
    shared_ptr_toy(shared_ptr_toy &oth) {
        // Сперва копируем данные
        obj = oth.obj;
        count = oth.count;
        // Увеличиваем кол-во объектов
        ++(*count);
    }

    // Конструктор с передачей имени
    explicit shared_ptr_toy(const char *name) {
        obj = new Toy(name);
        count = new int(1);
    }

    // Оператор присваивания копирования
    shared_ptr_toy &operator=(const shared_ptr_toy &oth) {
        if (this != &oth) {
            // Уменьшаем счетчик текущего указателя
            // Так как данные внутри указателя будут удалены
            reset();
            // Заносим данные внутрь текущего указателя
            obj = oth.obj;
            count = oth.count;
            // Увеличиваем счетчик нового указателя
            ++(*count);
        }
        return *this;
    }

    ~shared_ptr_toy() noexcept {
        // При удалении указателя, удаляется только один объект
        reset();
    }

    // Метод сброса указателя
    void reset() {
        // Если объект или кол-во пустое, то ничего не делаем
        if (!obj || !count) return;
        // Если кол-во объектов больше одного, то достаточно уменьшить кол-во указателей
        if (*count > 1) {
            --(*count);
        } else {
            // В другом случае, удаляем объект и обнуляем счетчик
            delete obj;
            delete count;
            // При удалении, внутри объекта еще что-то лежит, поэтому заносим NULL
            count = nullptr;
            obj = nullptr;
        }
    }

    // Получаем имя
    std::string getToyName() {
        if (count == nullptr) return "Nothing";
        return obj->getName();
    }

    // Получение количества ссылок. Не забываем про то что это указатель
    int use_count() const {
        return count ? *count : 0;
    }
};

// Сервисная функция для создания new toy
shared_ptr_toy make_shared_toy(const std::string &name) {
    return shared_ptr_toy(new Toy{name});
}

// Тестовая программа
void mod31ex2() {
    shared_ptr_toy toy_01 = make_shared_toy("ball");
    shared_ptr_toy toy_02(toy_01);
    shared_ptr_toy toy_03("duck");
    std::cout << "=================================================" << std::endl;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
            << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
            << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    toy_02 = toy_03;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
            << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
            << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    toy_01.reset();
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
            << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
            << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
}