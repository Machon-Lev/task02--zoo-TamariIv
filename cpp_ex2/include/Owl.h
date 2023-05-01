#pragma once
#include <iostream>
#include <vector>
#include "Animal.h"


class Owl: public Animal
{
	static const std::vector<Location> dirSteps;
	int dir;

public:
	Owl(const std::string& _name, const Location& _location) : Animal(_name, _location)
	{
		dir = (std::rand() % 4);
	}
	virtual void printDetails() const;
	virtual char getInitial() const;
	virtual void step();
	void move() override;
	virtual void turnVertically() override {};
	virtual void turnHorizontally() override {};
};

