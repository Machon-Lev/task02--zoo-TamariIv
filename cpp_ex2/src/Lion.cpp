#include "Lion.h"

// Vector to represnt all the possible steps for lion
const std::vector<Location> Lion::dirSteps = { Location(0, 2), Location(0,-2) };

void Lion::printDetails() const
{
	std::cout << "Name: " << this->name << std::endl << "Type: Lion\nLocation: " << this->location << std::endl;
}

char Lion::getInitial() const
{
	return 'L';
}

// Make a lion step
void Lion::step() {
	if (!moving)
		return;
	this->location += dirSteps[dir];
	if (this->location.col < 0) {
		turnHorizontally();
		location.col = 0;
	}
	else if (this->location.col >= 40) {
		turnHorizontally();
		location.col = 39;
	}
}

// Enable the animal moving and randomize a new direction
void Lion::move()
{
	dir = (std::rand() % 2);
	this->moving = true;
}

// Turn around to opposite direction
void Lion::turnHorizontally()
{
	if (dir)
		dir = 0;
	else
		dir = 1;
}
