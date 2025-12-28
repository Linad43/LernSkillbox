#include "..\header_modul27.h"

class House {
	std::string elfName;
	bool hasLive = false;
public:
	void setNameElf(std::string name) {
		elfName = name;
		setHasLive();
	}
	std::string getNameElf() {
		return elfName;
	}
	void setHasLive() {
		if (!elfName.empty() && elfName!="none") {
			hasLive = true;
		}
		else {
			hasLive = false;
		}
	}
	bool getHasLive() {
		return hasLive;
	}
	House() {
		std::string name;
		std::cin >> name;
		setNameElf(name);
	}
	House(std::string name) {
		setNameElf(name);
	}
};

class MediumBranch {
	std::vector<House> houses;
public:
	std::vector<House> *getHouses() {
		return &houses;
	}
	MediumBranch() {
		std::cout << "Medium branch, one house, input name elf:\n";
		House *house = new House();
		houses.push_back(*house);
		delete house;
	}
};

class BigBranch {
	std::vector<MediumBranch> mediumBranches;
	std::vector<House> houses;
public:
	std::vector<MediumBranch> *getMediumBranches() {
		return &mediumBranches;
	}
	std::vector<House> *getHouses() {
		return &houses;
	}
	BigBranch() {
		int countHouseInBigBranch = random(1, 2);
		switch (countHouseInBigBranch)
		{
		case 1: {
			std::cout << "Big branch, one house, input name elf:\n";
			House *house = new House();
			houses.push_back(*house);
			delete house;
			break;
		}
		case 2: {
			std::cout << "Big branch, two house, input name first elf:\n";
			for (int i = 0; i < 2; i++) {
				House *house = new House();
				houses.push_back(*house);
				if (i == 0) {
					std::cout << "Input name second elf:\n";
				}
				delete house;
			}
			break;
		}
		default:
			break;
		}
		int countMedium = random(2, 3);
		for (int i = 0; i < countMedium; i++) {
			MediumBranch *mediumBranch = new MediumBranch();
			mediumBranches.push_back(*mediumBranch);
			delete mediumBranch;
		}
	}
};

class Tree {
	std::vector<BigBranch> bigBranches;
public:
	std::vector<BigBranch> *getBigBranches() {
		return &bigBranches;
	}
	Tree() {
		int countBigBranches = random(3, 5);
		for (int i = 0; i < countBigBranches; i++) {
			BigBranch *bigBranch = new BigBranch();
			bigBranches.push_back(*bigBranch);
			delete bigBranch;
		}
	}
};

void mod27ex3() {
	std::cout << "3. Деревня эльфов.\n";
	std::vector<Tree> trees;
	int countTrees = 1;
	for (int i = 0; i < countTrees; i++) {
		Tree *tree = new Tree();
		trees.push_back(*tree);
	}
	std::string inputName;
	std::cout << "Input names elf for found:\n";
	std::cin >> inputName;
	bool found = false;

	int iTree, iBig, iMed, iTreeFound = -1, iBigFound = -1, iMedFound = -1;

	for (iTree = 0; iTree < trees.size() && !found; iTree++) {
		auto bufTree = trees[iTree];
		for (iBig = 0; iBig < bufTree.getBigBranches()->size() && !found; iBig++) {
			auto bufBigBranches = (*bufTree.getBigBranches())[iBig];
			for (int iBigHouse = 0; iBigHouse < bufBigBranches.getHouses()->size() && !found; iBigHouse++) {
				auto bufHouse = (*bufBigBranches.getHouses())[iBigHouse];
				if (bufHouse.getNameElf() == inputName) {
					iTreeFound = iTree;
					iBigFound = iBig;
					found = true;
				}
			}
			for (iMed = 0; iMed < bufBigBranches.getHouses()->size() && !found; iMed++) {
				auto bufHouse = (*bufBigBranches.getMediumBranches())[iMed].getHouses()->begin();
				if (bufHouse->getNameElf() == inputName) {
					iTreeFound = iTree;
					iBigFound = iBig;
					iMedFound = iMed;
					found = true;
				}
			}
		}
	}
	
	if (found) {
		int sum = -1;
		auto bufHouses1 = (*trees[iTreeFound].getBigBranches())[iBigFound].getHouses();
		for (int iScore = 0; iScore < bufHouses1->size(); iScore++) {
			sum += bufHouses1[iScore].begin()->getHasLive();
		}
		auto bufHouses2 = (*(*trees[iTreeFound].getBigBranches())[iBigFound].getMediumBranches());
		for (int iScore = 0; iScore < bufHouses2.size(); iScore++) {
			sum += bufHouses2[iScore].getHouses()->begin()->getHasLive();
		}
		std::cout << "The elf " << inputName << " has " << sum << " neighbors\n";
	}
	else {
		std::cout << "Elf not found!\n";
	}

}