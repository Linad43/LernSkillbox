#include "..\header_modul26.h"

enum Status {
    PLAY, PAUSE, NEXT, STOP
};

std::tm createRandDate() {
    time_t t;
    std::tm tm;
    time(&t);
    tm = *localtime(&t);
    tm.tm_year -= randomInt(0, 40);
    return tm;
}

class Track {
    std::string name;
    std::tm dateCreate;
    int timeTrack;

public:
    Track(std::string nameTrack = "") {
        name = nameTrack;
        dateCreate = createRandDate();
        timeTrack = randomInt(50, 4 * 60);
    }

    std::string timeToString() {
        int min = timeTrack / 60;
        int sec = timeTrack % 60;
        return std::to_string(min) + ":" + std::to_string(sec);
    }

    std::string dateToString() {
        return std::to_string(dateCreate.tm_year);
    }

    std::string toString() {
        return "name: " + name
               + "\ndate: " + dateToString()
               + "\ntime: " + timeToString()
               + "\n";
    }

    static std::tm createRandDate() {
        time_t t;
        std::tm tm;
        time(&t);
        tm = *localtime(&t);
        tm.tm_year -= randomInt(0, 40);
        return tm;
    }
};

class Player {
    //public:
    std::map<std::string, Track> tracks;
    std::map<std::string, Track>::iterator iter{tracks.begin()};

public:
    void addTrack(std::string nameTrack) {
        tracks[nameTrack] = Track(nameTrack);
    }

    void play() {
        std::string nameTrack;
        std::cout << "Input track name:\n";
        std::cin >> nameTrack;
        if (tracks.count(nameTrack)) {
            std::cout << tracks[nameTrack].toString();
        } else {
            std::cout << "Not found track\n";
        }
    }

    void pause() {
        std::cout << "Track pause\n";
    }

    void next() {
        for (int i = randomInt(1, tracks.size() - 1); i > 0; i--) {
            if (iter == tracks.end()) {
                iter = tracks.begin();
            }
            iter++;
            if (iter == tracks.end()) {
                iter = tracks.begin();
            }
        };
        std::cout << "Play next track:\n";
        std::cout << iter->second.toString();
    }

    void stop() {
        std::cout << "Track stop\n";
    }
};


void mod26ex1() {
    std::cout << "1. Реализовать программу имитации аудиоплеера.\n";
    Player player = Player();
    player.addTrack("one");
    player.addTrack("two");
    player.addTrack("three");
    player.addTrack("four");
    player.addTrack("five");
    player.addTrack("six");
    std::string command;
    Status status = STOP;
    Status changeStatus = STOP;

    while (true) {
        std::cout << "Input command:\n";
        std::cin >> command;
        if (command == "play") {
            changeStatus = PLAY;
        } else if (command == "pause") {
            changeStatus = PAUSE;
        } else if (command == "next") {
            changeStatus = NEXT;
        } else if (command == "stop") {
            changeStatus = STOP;
        } else if (command == "exit") {
            break;
        }
        switch (changeStatus) {
            case PLAY:
                if (status != changeStatus) {
                    player.play();
                    status = changeStatus;
                }
                break;
            case PAUSE:
                if (status != changeStatus && status != STOP) {
                    player.pause();
                    status = changeStatus;
                }
                break;
            case NEXT:
                player.next();
                status = PLAY;
                break;
            case STOP:
                if (status != STOP) {
                    player.stop();
                    status = changeStatus;
                }
                break;
            default:
                break;
        }
    }
}
