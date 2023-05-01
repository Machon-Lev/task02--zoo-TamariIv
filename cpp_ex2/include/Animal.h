#pragma once
#include "Location.h"


class Animal
{
protected:
	std::string name;
	Location location;
	bool moving;

public:

	Animal(std::string _name, Location l)
	{
		name = _name;
		location = l;
		moving = true;
	}
	virtual ~Animal() = default;

	virtual void printDetails() const = 0;
	virtual char getInitial() const = 0;
	Location getLocation() const;
	virtual void step() = 0;
	void stop();
	virtual void move();
	virtual void turnVertically() = 0;
	virtual void turnHorizontally() = 0;

};

