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

    std::string toString() const {
        return nameHero + " - " + nameActor;
    }
};

class Film {
    std::string name;
    std::string country;
    std::string date;
    std::string studio;
    std::string author;
    std::string director;
    std::string producer;
    std::vector<MainActor> actors;

public:
    Film(
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

    nlohmann::json serialization() {
        nlohmann::json j;
        j["name"] = delSpaceBegEnd(name);
        j["country"] = delSpaceBegEnd(country);
        j["date"] = delSpaceBegEnd(date);
        j["studio"] = delSpaceBegEnd(studio);
        j["author"] = delSpaceBegEnd(author);
        j["director"] = delSpaceBegEnd(director);
        j["producer"] = delSpaceBegEnd(producer);
        j["actors"] = actorsToString();
        return j;
    }

    static Film deserialization(nlohmann::json j) {
        std::string name;
        j.at("name").get_to(name);
        std::string country;
        j.at("country").get_to(country);
        std::string date;
        j.at("date").get_to(date);
        std::string studio;
        j.at("studio").get_to(studio);
        std::string author;
        j.at("author").get_to(author);
        std::string director;
        j.at("director").get_to(director);
        std::string producer;
        j.at("producer").get_to(producer);
        std::string actorsStr;
        j.at("actors").get_to(actorsStr);
        auto actors = actorsToVector(actorsStr);
        return Film(
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

        for (const auto &actor: this->actors) {
            if (flag) {
                result += "\n\t";
            }
            result += delSpaceBegEnd(actor.toString()) + "; ";
        }
        return result;
    }

    static std::vector<MainActor> actorsToVector(const std::string &actorsStr) {
        auto actors = splitString(actorsStr, "; ");
        std::vector<MainActor> result;
        for (const auto &actor: actors) {
            if (actor != "") {
                auto buf = splitString(actor, " - ");
                result.emplace_back(delSpaceBegEnd(buf[0]), delSpaceBegEnd(buf[1]));
            }
        }
        return result;
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
};

void mod32ex1() {
    std::cout << "1. Сделать JSON-документ с информацией о киноленте.\n";
    Film film = Film(
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
    );
    std::cout<<film.toString();
    std::cout << std::endl;

    std::ofstream jsonFile;
    jsonFile.open("modul32.json");
    nlohmann::json json;
    json = film.serialization();
    jsonFile << json;
    jsonFile.close();

    std::ifstream jsonFile2;
    jsonFile2.open("modul32.json");
    std::string jsonStr;
    nlohmann::json json2;
    std::getline(jsonFile2, jsonStr);
    json2 = nlohmann::json::parse(jsonStr);
    Film film2 = Film::deserialization(json2);
    jsonFile2.close();

    std::cout<<film2.toString();
    std::cout << std::endl;
}
