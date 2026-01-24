#include "header_modul32.h"
#include "nlohmann/json.hpp"

class MainActor {
    std::string nameHero;
    std::string nameActor;

public:
    MainActor(
        const std::string &nameHero,
        const std::string &nameActor
    ) {
        this->nameHero = nameHero;
        this->nameActor = nameActor;
    }

    std::string getNameHero() {
        return this->nameHero;
    }

    std::string getNameActor() {
        return this->nameActor;
    }

    std::string toString() {
        return nameHero + " - " + nameActor;
    }
};

class Films {
    std::string name;
    std::string country;
    std::string date;
    std::string studio;
    std::string author;
    std::string director;
    std::string producer;
    std::vector<MainActor> actors;

public:
    Films(
        const std::string &name,
        const std::string &country,
        const std::string &date,
        const std::string &studio,
        const std::string &author,
        const std::string &director,
        const std::string &producer,
        const std::vector<MainActor> &actors
    ) {
        this->name = name;
        this->country = country;
        this->date = date;
        this->studio = studio;
        this->author = author;
        this->director = director;
        this->producer = producer;
        this->actors = actors;
    }

    Films();

    nlohmann::json serialization(/*const std::string &name*/) {
        nlohmann::json j;
        // j["name"] = name;
        j[name]["country"] = delSpaceBegEnd(country);
        j[name]["date"] = delSpaceBegEnd(date);
        j[name]["studio"] = delSpaceBegEnd(studio);
        j[name]["author"] = delSpaceBegEnd(author);
        j[name]["director"] = delSpaceBegEnd(director);
        j[name]["producer"] = delSpaceBegEnd(producer);
        for (auto actor: actors) {
            j[name]["actors"][delSpaceBegEnd(actor.getNameHero())] = delSpaceBegEnd(actor.getNameActor());
        }
        // j[name]["actors"] = actorsToString();
        return j;
    }

    static std::vector<MainActor> actorsToVector(const std::map<std::string, std::string> &actors) {
        std::vector<MainActor> result;
        for (auto &actor: actors) {
            result.emplace_back(actor.first, actor.second);
        }
        return result;
    }

    static Films deserialization(nlohmann::json j, const std::string &name) {
        // std::string name;
        // j.at(name).at("name").get_to(name);
        std::string country;
        j.at(name).at("country").get_to(country);
        std::string date;
        j.at(name).at("date").get_to(date);
        std::string studio;
        j.at(name).at("studio").get_to(studio);
        std::string author;
        j.at(name).at("author").get_to(author);
        std::string director;
        j.at(name).at("director").get_to(director);
        std::string producer;
        j.at(name).at("producer").get_to(producer);
        std::map<std::string, std::string> actorsPair;
        j.at(name).at("actors").get_to(actorsPair);
        auto actors = actorsToVector(actorsPair);
        return Films(
            name,
            country,
            date,
            studio,
            author,
            director,
            producer,
            actors
        );
    }

    std::string actorsToString(bool flag = false) {
        std::string result;

        for (auto &actor: this->actors) {
            if (flag) {
                result += "\n\t";
            }
            result += actor.toString() + "; ";
        }
        return result;
    }

    // static std::vector<MainActor> actorsToVector(const std::string &actorsStr) {
    //     auto actors = splitString(actorsStr, "; ");
    //     std::vector<MainActor> result;
    //     for (const auto &actor: actors) {
    //         if (actor != "") {
    //             auto buf = splitString(actor, " - ");
    //             result.emplace_back(delSpaceBegEnd(buf[0]), delSpaceBegEnd(buf[1]));
    //         }
    //     }
    //     return result;
    // }
    std::string getName() {
        return this->name;
    }

    std::string toString() {
        return "name: " + name +
               "\ncountry: " + country +
               "\ndate: " + date +
               "\nstudio: " + studio +
               "\nauthor: " + author +
               "\ndirector: " + director +
               "\nproducer: " + producer +
               "\nactors: " + actorsToString(true) + "\n";
    }

    MainActor *findActor(const std::string &actorName) {
        for (auto &actor: actors) {
            auto names = splitString(actor.getNameActor(), " ");
            for (auto &name: names) {
                if (name == actorName) {
                    return &actor;
                }
            }
        }
        return nullptr;
    }

    void getActorFilm(MainActor actor) {
        std::cout << name << "\n\t" << actor.toString() << std::endl;
    }
};

// class OutFilm {
//     std::map<std::string, Films> films;
//
// public:
//     void addFilm(
//         const std::string &name,
//         const Films &film) {
//         films[name] = film;
//     }
//
//     Films getFilm(const std::string &name) {
//         return films[name];
//     }
//
//     std::string toString() {
//         std::string result = "";
//         for (auto &film: films) {
//             result += "name: " + film.first + "\n" + film.second.toString();
//         }
//         return result;
//     }
//
//     nlohmann::json serialization(const std::string &name) {
//         return films[name].serialization(name);
//     }
//
//     nlohmann::json serialization() {
//         nlohmann::json result;
//         for (auto &film: films) {
//             result.emplace_back(film.second.serialization(film.first));
//         }
//         return result;
//     }
// };

void mod32ex2() {
    std::cout << "2. Проанализировать JSON-базу данных о фильмах.\n";

    std::vector<Films> films;
    films.push_back(
        Films(
            "Салют-7",
            "Россия",
            "2017",
            "Россия-1",
            "Алексей Самолётов",
            "Клим Шипенко",
            "Антон Златопольский",
            {
                MainActor(
                    "Владимир Фёдоров",
                    "Владимир Вдовиченков"
                ),
                MainActor(
                    "Виктор Алёхин",
                    "Павел Деревянко"
                ),
                MainActor(
                    "Нина Фёдорова",
                    "Мария Миронова"
                ),
                MainActor(
                    "Лилия Алёхина",
                    "Любовь Аксёнова"
                ),
                MainActor(
                    " Валерий Шубин",
                    "Александр Самойленко"
                )
            }
        )
    );
    films.push_back(
        Films(
            "Время первых",
            "Россия",
            "2017",
            "Россия-1",
            "Юрий Коротков",
            "Юрий Потеенко",
            "Тимур Бекмамбетов",
            {
                MainActor(
                    "Алексей Леонов",
                    "Евгений Миронов"
                ),
                MainActor(
                    "Павел Беляев",
                    "Константин Хабенский"
                )
            }
        )
    );
    films.push_back(
        Films(
            "На игре",
            "Россия",
            "2009",
            "СТС",
            "Павел Санаев",
            "Павел Санаев",
            "Александр Бондарев",
            {
                MainActor(
                    "Дмитрий «Вампир» Орлов",
                    "Сергей Чирков"
                ),
                MainActor(
                    "Руслан «Док» Авдеев",
                    "Павел Прилучный"
                ),
                MainActor(
                    "Рита Смирнова",
                    "Марина Петренко"
                )
            }
        )
    );
    for (auto &film: films) {
        std::cout << film.toString() << std::endl;
    }
    std::ofstream jsonFile;
    jsonFile.open("modul32ex2.json");
    nlohmann::json json;
    for (auto &film: films) {
        json.push_back(film.serialization());
    }
    jsonFile << json;
    jsonFile.close();
    films.clear();

    std::ifstream jsonFile2;
    jsonFile2.open("modul32ex2.json");
    std::string jsonStr;
    nlohmann::json json2;
    std::getline(jsonFile2, jsonStr);
    json2 = nlohmann::json::parse(jsonStr);
    for (auto iter = json2.begin(); iter != json2.end(); ++iter) {
        films.push_back(Films::deserialization(
            iter.value(),
            splitString(iter.value().dump(), "\"")[1]
        ));
    }
    // Films films2 = Films::deserialization(json2, "Салют-7");
    jsonFile2.close();

    for (auto &film: films) {
        std::cout << film.toString() << std::endl;
    }
    // std::cout << films2.toString();
    std::cout << std::endl;

    std::cout << "Find actor \"Павел\"\n";
    for (auto &film: films) {
        if (auto buf = film.findActor("Павел"); buf!=nullptr) {
            film.getActorFilm(*buf);
        }
    }
    std::cout << "Find actor \"Деревянко\"\n";
    for (auto &film: films) {
        if (auto buf = film.findActor("Деревянко"); buf!=nullptr) {
            film.getActorFilm(*buf);
        }
    }
}
