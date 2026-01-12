#include "header_modul21.h"
#define COUNT_TYPE_ROOM 8
#define COUNT_TYPE_BUILDING 4

enum typeRoom {
	living,
	children,
	bethroom,
	kitchen,
	hall,
	hallway,
	dining,
	restroom
};

std::string typeRoomString[] = {
	"living",
	"children",
	"bethroom",
	"kitchen",
	"hall",
	"hallway",
	"dining",
	"restroom"
};

enum typeBuilding {
	home,
	garage,
	barn,
	bathhouse
};

std::string typeBuildingString[] = {
	"home",
	"garage",
	"barn",
	"bathhouse"
};

struct size {//Размеры
	int length = 0;
	int width = 0;

	void setLength() {
		int buf;
		do {
			std::cout << "Length = " << std::endl;
			std::cin >> buf;
			if (buf > 0) {
				length = buf;
				break;
			}
			else {
				std::cout << "Input error. Try again.\n";
			}
		} while (true);
	}

	void setWidth() {
		int buf;
		do {
			std::cout << "Width = " << std::endl;
			std::cin >> buf;
			if (buf > 0) {
				width = buf;
				break;
			}
			else {
				std::cout << "Input error. Try again.\n";
			}
		} while (true);
	}

	int area() {
		return length * width;
	}
};

struct room {//комната в строении
	typeRoom type = living;
	size sizeRoom;
	int level = 1;

	void randTypeRoom() {
		typeRoom test = static_cast<typeRoom>(rand() % COUNT_TYPE_ROOM);
	}
};

struct building {//Строение на участке
	typeBuilding type = home;
	size sizeBuilding;
	int countLevel = 1;
	std::vector <room> rooms;

	void setLevel() {
		int buf;
		do {
			std::cout << "Level = " << std::endl;
			std::cin >> buf;
			if (buf > 0) {
				countLevel = buf;
				break;
			}
			else {
				std::cout << "Input error. Try again.\n";
			}
		} while (true);
	}

	bool addRoom(room newRoom) {
		if (newRoom.sizeRoom.area() <= (sizeBuilding.area() - areaOccupied(newRoom.level))) {
			rooms.push_back(newRoom);
			return true;
		}
		else {
			std::cout << "There is not enough room space\n";
			return false;
		}
	}

	int areaOccupied(int levelNeed) {
		int result = 0;
		for (int i = 0; i < rooms.size(); i++) {
			if (rooms[i].level == levelNeed) {
				result += rooms[i].sizeRoom.area();
			}
		}
		return result;
	}
};

struct land {//Участок
	size sizeLand;
	std::vector <building> buildingInLand;

	bool addBuilding(building newBuilding) {
		if (newBuilding.sizeBuilding.area() <= (sizeLand.area() - areaOccupied())) {
			buildingInLand.push_back(newBuilding);
			return true;
		}
		else {
			std::cout << "There is not enough land space\n";
			return false;
		}
	}

	int areaOccupied() {
		int result = 0;
		for (int i = 0; i < buildingInLand.size(); result += buildingInLand[i++].sizeBuilding.area());
		return result;
	}
};
void mod21ex2() {
	std::cout << "2. Модель данных для посёлка.\n";
	std::vector <land> lands;
	int countLands, countBuilding, choice, countRooms;
	int buf;
	std::cout << "Input count lands: ";
	std::cin >> countLands;
	for (int i = 0; i < countLands; i++) {
		land newLand;
		lands.push_back(newLand);
		std::cout << "Input size land:\n";
		lands[i].sizeLand.setLength();
		lands[i].sizeLand.setWidth();
		std::cout << "Input count building in " << i + 1 << " land: ";
		std::cin >> countBuilding;
		for (int j = 0; j < countBuilding; j++) {
			building newBuilding;
			do {
				std::cout << "Input size building:\n";
				newBuilding.sizeBuilding.setLength();
				newBuilding.sizeBuilding.setWidth();
			} while (!lands[i].addBuilding(newBuilding));
			std::cout << j + 1 << " building is:\n";
			for (int k = 0; k < COUNT_TYPE_BUILDING; k++) {
				std::cout << k + 1 << ". " << typeBuildingString[k] << std::endl;
			}
			std::cin >> choice;
			lands[i].buildingInLand[j].type = static_cast<typeBuilding>(choice - 1);
			if (lands[i].buildingInLand[j].type == home) {
				std::cout << "Input count level in home:\n";
				lands[i].buildingInLand[j].setLevel();
				countRooms = 0;
				for (int k = 0; k < lands[i].buildingInLand[j].countLevel; k++) {
					do {
						std::cout << "Level " << k + 1 << ", free area left "
							<< lands[i].buildingInLand[j].sizeBuilding.area() - lands[i].buildingInLand[j].areaOccupied(k)
							<< std::endl;
						if (lands[i].buildingInLand[j].areaOccupied(k) < lands[i].buildingInLand[j].sizeBuilding.area())
							break;
						std::cout << "1. Add room.\n";
						std::cout << "2. Next level.\n";
						std::cin >> choice;
						if (choice == 1) {
							room newRoom;
							newRoom.level = k;
							do {
								std::cout << "Input size room:\n";
								newRoom.sizeRoom.setLength();
								newRoom.sizeRoom.setWidth();
							} while (!lands[i].buildingInLand[j].addRoom(newRoom));
							std::cout << "This room is:\n";
							for (int n = 0; n < COUNT_TYPE_ROOM; n++) {
								std::cout << n + 1 << ". " << typeRoomString[n] << std::endl;
							}
							std::cin >> choice;
							lands[i].buildingInLand[j].rooms[countRooms++].type = static_cast<typeRoom>(choice - 1);
						}
						else {
							break;
						}
					} while (true);
				}
			}
		}
	}

	std::cout << "Output all lands:\n";
	for (int i = 0; i < lands.size(); i++) {
		std::cout << "Land " << i + 1 << " :";
		std::cout << "  size: " << lands[i].sizeLand.length << "x" << lands[i].sizeLand.width << std::endl;
		std::cout << "  building:\n";
		for (int j = 0; j < lands[i].buildingInLand.size(); j++) {
			std::cout << "    " << typeBuildingString[lands[i].buildingInLand[j].type] << ":\n";
			std::cout << "      size: " << lands[i].buildingInLand[j].sizeBuilding.length << "x" << lands[i].buildingInLand[j].sizeBuilding.width << "\n";
			if (lands[i].buildingInLand[j].type == home) {
				for (int lvl = 0; lvl < lands[i].buildingInLand[j].countLevel; lvl++) {
					for (int k = 0; k < lands[i].buildingInLand[j].rooms.size(); k++) {
						if (lands[i].buildingInLand[j].rooms[k].level == lvl + 1)
							std::cout << "\tlvl " << lvl << ":\n";
							std::cout << "\t  " << typeRoomString[lands[i].buildingInLand[j].rooms[k].type] << "\n";
					}
				}
			}
		}
	}
}