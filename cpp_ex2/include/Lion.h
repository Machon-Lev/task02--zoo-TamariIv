#pragma once
#include "Animal.h"
#include <vector>

class Lion: public Animal
{
	static const std::vector<Location> dirSteps;
	int dir;

public:
	Lion(const std::string& _name, const Location& _location): Animal(_name, _location)
	{
		dir = (std::rand() % 2);
	}
	virtual void printDetails() const;
	virtual char getInitial() const;	
	virtual void step();
	void move() override;
	virtual void turnHorizontally() override;
	virtual void turnVertically() override {};

};

