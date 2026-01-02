#include "..\header_modul28.h"

const double MAX_DISTANCE = 100;
int nowCountSwimmer = 0;
std::mutex cout_mutex;

class Swimmer {
	std::string name = "player " + std::to_string(++nowCountSwimmer);
	double speed = (double)random((float)1, 10.0);
	double distance = 0;
public:
	std::string getName() {
		return name;
	}
	void setName(std::string name) {
		this->name = name;
	}
	double getSpeed() {
		return speed;
	}
	void setSpeed(double speed) {
		this->speed = speed;
	}
	double getDistance() {
		return distance;
	}
	void setDistance(double distance) {
		this->distance = distance;
	}
	double timeAllDistance() {
		return MAX_DISTANCE / speed;
	}
	void swim() {
		while (distance < MAX_DISTANCE) {
			if ((MAX_DISTANCE - distance) >= speed) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
				distance += speed;
			}
			else {
				int finalTimeMiliSec = ((MAX_DISTANCE - distance) / speed) * 1000;
				std::this_thread::sleep_for(std::chrono::milliseconds(finalTimeMiliSec));
				distance = MAX_DISTANCE;
			}
			cout_mutex.lock();
			std::cout << "Player \"" << name << "\" swim " << distance << " distance.\n";
			cout_mutex.unlock();

		}
		cout_mutex.lock();
		std::cout << "-----Player \"" << name << "\" finished.-----\n";
		cout_mutex.unlock();
	}
	std::string toString() {
		return "{" + name + "; " + std::to_string(speed) + "}";
	}
	bool operator<(const Swimmer& x) const {
		return speed > x.speed;
	}
};



void swim(Swimmer swemmer) {
	swemmer.swim();
}

void mod28ex1() {
	std::cout << "1. Реализовать симуляцию заплыва на 100 метров.\n";

	int counrSwimmers = 6;
	std::vector<Swimmer> swimmers;
	for (int i = 0; i < counrSwimmers; i++) {
		Swimmer swimmer = Swimmer();
		std::cout << swimmer.toString();
		std::cout << std::endl;
		swimmers.push_back(swimmer);
	}

	std::vector<std::thread> treadSwimmers;

	for (int i = 0; i < swimmers.size(); i++) {
		treadSwimmers.emplace_back(swim, swimmers[i]);
	}

	for (auto iter = treadSwimmers.begin(); iter != treadSwimmers.end(); iter++) {
		iter->join();
	}

	std::sort(swimmers.begin(), swimmers.end());
	int place = 1;
	for (std::vector<Swimmer>::iterator iter = swimmers.begin(); iter != swimmers.end(); iter++, place++) {
		std::cout << place << ". " << iter->getName() << " - " << iter->timeAllDistance() << " sec.\n";
	}

}