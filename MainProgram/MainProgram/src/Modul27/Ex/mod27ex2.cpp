#include "header_modul27.h"

class Worker {
	int id;
	bool isBusy = false;
public:
	int getId() {
		return id;
	}
	bool getIsBusy() {
		return isBusy;
	}
	void setId(int id) {
		this->id = id;
	}
	void setIsBusy(bool isBusy) {
		this->isBusy = isBusy;
	}
};

class Manager {
	std::string name;
	std::vector<Worker> teamWorkers;

public:

	std::string getName() {
		return name;
	}

	std::vector<Worker> getTeamWorkers() {
		return teamWorkers;
	}

	void setName(std::string name) {
		this->name = name;
	}

	void addToTeamWorkers(Worker worker) {
		teamWorkers.push_back(worker);
	}

	void setTeamWorkers(std::vector<Worker> teamWorkers) {
		this->teamWorkers = teamWorkers;
	}

	bool allWorkersAreBusy() {
		for (auto iter = teamWorkers.begin(); iter != teamWorkers.end(); iter++) {
			if (!iter->getIsBusy()) {
				return false;
			}
		}
		return true;
	}

	bool assignTasks(std::string managerName) {
		int workerIndex = rand() % teamWorkers.size();

		if (!teamWorkers[workerIndex].getIsBusy()) {
			char taskType = 'A' + rand() % 3;

			std::cout << "Менеджеру " << managerName << ": назначен рабочий №" << teamWorkers[workerIndex].getId()
				<< ", задача типа '" << taskType << "'\n";

			teamWorkers[workerIndex].setIsBusy(true);
			return true;
		}

		return false;
	}
};

void mod27ex2() {
	std::cout << "2. Симуляция работы компании.\n";

	int numTeams, workersPerTeam;
	std::cout << "Кол-во команд: ";
	std::cin >> numTeams;
	std::cout << "Кол-во работников в команде: ";
	std::cin >> workersPerTeam;

	std::vector<Manager> managers(numTeams);

	int managerId = 1;
	for (auto iter = managers.begin(); iter != managers.end(); iter++) {
		iter->setName("Менеджер-" + std::to_string(managerId++));

		for (int j = 0; j < workersPerTeam; j++) {
			Worker newWorker = Worker();
			newWorker.setId(j + 1);
			iter->addToTeamWorkers(newWorker);
		}
	}

	while (true) {
		std::cout << "Введите целое число для распределения задач (-1 для завершения): ";
		int taskNumber;
		std::cin >> taskNumber;

		if (taskNumber <= 0) {
			break;
		}

		bool allWorkersAssigned = false;
		while (taskNumber > 0 && !allWorkersAssigned) {
			int indexManagers = rand() % managers.size();
			if (managers[indexManagers].assignTasks(managers[indexManagers].getName())) {
				taskNumber--;
			}
			allWorkersAssigned = true;
			for (auto iter = managers.begin(); iter != managers.end(); iter++) {
				if (!iter->allWorkersAreBusy()) {
					allWorkersAssigned = false;
					break;
				}
			}
		}

		if (allWorkersAssigned) {
			std::cout << "\nВсе рабочие получили задачи.\n";
			break;
		}
	}
}