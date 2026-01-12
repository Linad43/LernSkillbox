#include "header_modul28.h"

int numTrain = 0;
std::mutex mtxTrain, mtxCout;

enum statusTrain {
	WAIT, DRIVE, COMMING, WAITINSTATION, DEPART
};

class Train {
	char name = 'A' + numTrain++;
	statusTrain status = WAIT;
	int timeToStation = 10;
public:
	char getName() {
		return name;
	}
	void printStatus() {
		mtxCout.lock();
		switch (status)
		{
		case WAIT:
			std::cout << "Train \""<< name <<"\" wait task.\n";
			break;
		case DRIVE:
			std::cout << "Train \"" << name << "\" driwe to station.\n";
			break;
		case COMMING:
			std::cout << "Train \"" << name << "\" comming to station.\n";
			break;
		case WAITINSTATION:
			std::cout << "Train \"" << name << "\" wait in station.\n";
			break;
		case DEPART:
			std::cout << "Train \"" << name << "\" depart from the station.\n";
			break;
		default:
			break;
		}
		mtxCout.unlock();
	}
	statusTrain getStatus() {
		return status;
	}
	void setStatus(statusTrain status) {
		this->status = status;
		printStatus();
	}
	int getTimeToStation() {
		return timeToStation;
	}
	void setTimeToStation(double timeToStation) {
		this->timeToStation = timeToStation;
	}
	void driweTrainToStation() {
		setStatus(statusTrain::DRIVE);
		std::this_thread::sleep_for(std::chrono::seconds(timeToStation));
		setStatus(statusTrain::COMMING);
		while (!mtxTrain.try_lock()) {
			if (status != statusTrain::WAIT) {
				setStatus(statusTrain::WAIT);
			}
		}
		setStatus(statusTrain::WAITINSTATION);
		{
			mtxCout.lock();
			std::cout << "Train \"" << name << "\" wait command \"depart\".\n";
			mtxCout.unlock();
			std::string input = "";
			while (input != "depart") {
				/////
				mtxCout.lock();//или убрать для сообщения по прибытию
				std::cin >> input;
				mtxCout.unlock();
				/////
			}
			setStatus(statusTrain::DEPART);
			mtxTrain.unlock();
		}
	}

	Train() {
		setStatus(statusTrain::WAIT);
	};
};

void drive(Train train) {
	train.driweTrainToStation();
}

void mod28ex2() {
	std::cout << "2. Реализовать симуляцию работы вокзала.\n";
	int countTrain = 3;
	std::vector<Train> trains;
	for (int i = 0; i < countTrain; i++) {
		Train train = Train();
		std::cout << "Train " << train.getName() << " time to drive: ";
		int buf;
		try {
			std::cin >> buf;
			train.setTimeToStation(buf);
		}
		catch (...) { }
		trains.push_back(train);
	}

	std::vector<std::thread> threadTrains;
	for (int i = 0; i < trains.size(); i++) {
		threadTrains.emplace_back(drive, trains[i]);
	}
	for (auto iter = threadTrains.begin(); iter != threadTrains.end(); iter++) {
		iter->join();
	}

}