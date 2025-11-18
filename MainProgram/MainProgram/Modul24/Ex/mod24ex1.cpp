#include "..\header_modul24.h"
using namespace std::string_literals;
struct task {
	std::string name = "";
	int startTime = -1;
	int endTime = -1;
	int second = -1;

	void setSecond() {
		//std::cout << startTime << " - " << endTime << "\n";
		second = endTime - startTime;
		//std::cout << second << "\n";
	}

	std::string timeToString() {
		if (second >= 0) {
			int hour = 0;
			int min = 0;
			int sec = second;
			if (second >= 60) {
				min = sec / 60;
				sec %= 60;
			}
			if (min >= 60) {
				hour = min / 60;
				min %= 60;
			}
			std::string secStr, minStr, hourStr;
			if (sec > 9) {
				secStr = std::to_string(sec);
			}
			else {
				secStr = "0" + std::to_string(sec);
			}
			if (min > 9) {
				minStr = std::to_string(min);
			}
			else {
				minStr = "0" + std::to_string(min);
			}
			if (hour > 9) {
				hourStr = std::to_string(hour);
			}
			else {
				hourStr = "0" + std::to_string(hour);
			}
			return { hourStr + ":" + minStr + ":" + secStr };
		}
		return "Not finished";
	}

	std::string toString() {
		return name + " " + timeToString();
	}

	void clear() {
		name = "";
		startTime = -1;
		endTime = -1;
		second = -1;
	}
};

std::vector <task> tasks;

task menuBegin() {
	std::cout << "Input name task: ";
	std::string nameTask;
	std::cin >> nameTask;
	std::time_t t = std::time(nullptr);
	std::tm* local = std::localtime(&t);
	std::cout << "Task begin: " << std::put_time(local, "%H:%M:%S") << std::endl;
	return { nameTask, int(t) };
}

int menuEnd() {
	std::time_t t = std::time(nullptr);
	std::tm* local = std::localtime(&t);
	std::cout << "Task end: " << std::put_time(local, "%H:%M:%S") << std::endl;
	return t;
}

void menuStatus(task nowTask) {
	for (int i = 0; i < tasks.size(); i++) {
		std::cout << tasks[i].toString() << std::endl;
	}
	if (nowTask.name != "") {
		std::cout << nowTask.toString() << std::endl;
	}
}

void mod24ex1() {
	std::cout << "1. Реализовать программу учёта времени.\n";
	std::string input;
	task newTask;
	do {
		std::cin >> input;
		if (strToLow(input) == "begin") {
			if (newTask.startTime != -1) {
				newTask.endTime = menuEnd();
				newTask.setSecond();
				tasks.push_back(newTask);
				newTask.clear();
			}
			newTask = menuBegin();
		}
		else if (strToLow(input) == "end") {
			if (newTask.startTime != -1) {
				newTask.endTime = menuEnd();
				newTask.setSecond();
				tasks.push_back(newTask);
				newTask.clear();
			}
			else {
				std::cout << "Not started\n";
			}
		}
		else if (strToLow(input) == "status") {
			menuStatus(newTask);
		}
		else if (strToLow(input) == "exit") {
			break;
		}
	} while (true);
}