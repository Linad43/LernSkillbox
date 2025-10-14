#include "..\header_modul16.h"

double tempIn = 0;
double tempOut = 0;
bool move = false;
bool lightsIn = false;
bool lightsOut = false;
int colorTemp = 0;
bool heaters = false;
bool waterPipeHeating = false;
bool conditioner = false;

void strToLower(std::string text) {
	for (int i(0); i < text.size(); text[i] = tolower(text[i]), i++);
}

int setWaterPipeHeating() {
	if (!waterPipeHeating) {
		if (tempOut < 0) {
			return 1;
		}
	}
	else {
		if (tempOut > 5) {
			return  -1;
		}
	}
	return 0;
}

int setLightsOut() {
	time_t currentTime;
	struct tm* localTime;
	time(&currentTime);
	localTime = localtime(&currentTime);
	int hoursNow = localTime->tm_hour;
	int minNow = localTime->tm_min;

	if (!lightsOut) {
		if (hoursNow > 16 && hoursNow < 5 && move) {
			return 1;
		}
	}
	else {
		if (!(hoursNow > 16 && hoursNow < 5 && move))
			return -1;
	}
	return 0;
}

int setHeating() {
	if (!heaters) {
		if (tempIn < 22) {
			return 1;
		}
	}
	else {
		if (tempIn >= 25) {
			return -1;
		}
	}
	return 0;
}

bool setConditioner() {
	if (!conditioner) {
		if (tempIn >= 30) {
			return 1;
		}
	}
	else {
		if (tempIn <= 25) {
			return -1;
		}
	}
	return 0;
}

int setColorLight() {
	if (!lightsIn) {
		return 0;
	}
	time_t currentTime;
	struct tm* localTime;
	time(&currentTime);
	localTime = localtime(&currentTime);
	int hoursNow = localTime->tm_hour;
	int minNow = localTime->tm_min;
	int hoursBeg = 16;
	int hoursEnd = 20;
	int nowMins = minNow + hoursNow * 60;
	int begMins = hoursBeg * 60;
	int endMins = hoursEnd * 60;
	int maxMins = endMins - begMins;
	int range = 5000 - 2700;
	std::cout << "Time: " << hoursNow << ":" << minNow << std::endl;
	if (hoursNow >= 0 && hoursNow < 16) {
		return 5000;
	}
	else if (hoursNow >= 20) {
		return 2700;
	}
	else {
		return 5000 - ((range / maxMins) * (nowMins - begMins));
	}
}

void mod16ex5() {
	std::cout << "5. Умный дом.\n";
	for (int i = 0; i < 5; i++) {
		std::string moveStr, lightsStr, input, tempInStr, tempOutStr;
		std::vector <std::string> inputVector;
		bool moveIsOk = false, lightsIsOk = false, first = true;
		while (!moveIsOk || !lightsIsOk) {
			std::cout << "Temperature inside, temperature outside, movement, lights:\n";
			moveIsOk = false;
			lightsIsOk = false;
			while (std::cin.eof()) {
				std::cin.ignore(1);
			}

			std::getline(std::cin, input);
			

			inputVector = splitString(input, " ");
			try {
				//scanf("%3s", &tempInStr,3);
				/*tempIn = stod(tempInStr);
				tempOut = stod(tempOutStr);*/
				tempIn = stod(inputVector[0]);
				tempOut = stod(inputVector[1]);
				moveStr = inputVector[2];
				lightsStr = inputVector[3];
			}
			catch (...) {
				continue;
			}
			strToLower(moveStr);
			strToLower(lightsStr);
			if (moveStr == "yes") {
				move = true;
				moveIsOk = true;
			}
			else if (moveStr == "no") {
				move = false;
				moveIsOk = true;
			}
			if (lightsStr == "on") {
				lightsIn = true;
				lightsIsOk = true;
			}
			else if (lightsStr == "off") {
				lightsIn = false;
				lightsIsOk = true;
			}
		}


		colorTemp = setColorLight();
		switch (setWaterPipeHeating())
		{
		case -1: {
			std::cout << "Water pipe heating OFF!\n";
			waterPipeHeating = false;
			break;
		}
		case 1: {
			std::cout << "Water pipe heating ON!\n";
			waterPipeHeating = true;
			break;
		}
		default:
			break;
		}

		switch (setLightsOut())
		{
		case -1: {
			std::cout << "Lights outside OFF!\n";
			lightsOut = false;
			break;
		}
		case 1: {
			std::cout << "Lights outside ON!\n";
			lightsOut = true;
			break;
		}
		default:
			break;
		}

		switch (setHeating())
		{
		case -1: {
			std::cout << "Heaters OFF!\n";
			heaters = false;
			break;
		}
		case 1: {
			std::cout << "Heaters ON!\n";
			heaters = true;
			break;
		}
		default:
			break;
		}

		switch (setConditioner())
		{
		case -1: {
			std::cout << "Conditioner OFF!\n";
			conditioner = false;
			break;
		}
		case 1: {
			std::cout << "Conditioner ON!\n";
			conditioner = true;
			break;
		}
		default:
			break;
		}
		std::cout << "Color temperature: " << colorTemp << std::endl;
	}
}