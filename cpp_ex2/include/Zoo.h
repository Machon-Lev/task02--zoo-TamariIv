#pragma once
#include "Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include "Owl.h"
#include <vector>
#include <algorithm>


enum Commands
{
	STEP,
	STOP,
	MOVE,
	CREATE,
	DEL,
	DEL_ALL,
	HELP,
	EXIT
};

class Zoo
{
	std::vector<Animal*> animalsList;


public:
	Zoo() {
		initializeZoo();
	}
	void run();

private:
	void move(int idx);
	void stop(int idx);
	void create(std::string name, std::string type);
	void del(int idx);
	void delAll(std::string type);
	void help();
	void step();

	void printMap();
	void printList();

	Location randomizeLocation();
	void initializeZoo();
	static bool compareByLocation(const Animal* a1, const Animal* a2);
	int getCommand() const;
	bool validType(std::string type) const;
	bool validId(int id) const;

};

