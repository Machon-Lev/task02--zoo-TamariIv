#pragma once
#include "Animal.h"
#include <vector>

class Monkey: public Animal
{
	int turn;
	static const std::vector<Location> dirSteps;
	int dir;
	int stepSize;

public:
	Monkey(const std::string& _name, const Location& _location) : Animal(_name, _location)
	{
		turn = 0;
		dir = (std::rand() % 4);
		stepSize = (std::rand() % 2) + 1;
	}
	virtual void printDetails() const;
	virtual char getInitial() const;
	virtual void step();
	virtual void turnVertically() override;
	virtual void turnHorizontally() override;

private:
	void reassignSteps();

};

