#include "..\header_modul26.h"

enum status {
	PLAY, PAUSE, NEXT, STOP
};

class Track {

	std::string name;
	std::tm dateCreate;
	int timeTrack;

public:

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
};

class Player {
public:
	std::map <std::string, Track> tracks;
	std::map <std::string, Track>::iterator iter { tracks.begin() };

//public:

	void play() {
		std::string nameTrack;
		std::cout << "Input track name:\n";
		std::cin >> nameTrack;
		if (tracks.count(nameTrack)) {
			std::cout << tracks[nameTrack].toString();
		}
		else {
			std::cout << "Not found track\n";
		}
	}
	void pause() {
		std::cout << "Track pause\n";
	}
	void next() {

	}
};

void mod26ex1() {
	std::cout << "1. Реализовать программу имитации аудиоплеера.\n";
	Player player = Player();
	auto iter = player.tracks.begin();
}