#include "Owl.h"

// Vector to represent the possible steps for owl
const std::vector<Location> Owl::dirSteps = { 
	Location(-3, -3), 
	Location(3, -3), 
	Location(-3, 3), 
	Location(3, 3)
};

void Owl::printDetails() const
{
	std::cout << "Name: " << this->name << std::endl << "Type: Owl\nLocation: " << this->location << std::endl;
}

char Owl::getInitial() const
{
	return 'O';
}

// Make an owl step
void Owl::step()
{
	if (!moving)
		// If the owls moving is disabled - return
		return;
	this->location += dirSteps[dir];
	bool turnAround = false;
	// If any step is exceeding the board - 
	// fix location to be the closest location inside the board
	if (this->location.col < 0) {
		turnAround = true;
		location.col = 0;
	}
	else if (this->location.col >= 40) {
		turnAround = true;
		location.col = 39;
	}
	if (this->location.row < 0) {
		turnAround = true;
		location.row = 0;
	}
	else if (this->location.row >= 20) {
		turnAround = true;
		location.row = 19;
	}
	if (turnAround) {
		// If one of the edges of the board was reached - 
		// turn around to the opposite direction
		switch (dir)
		{
		case 0:
			dir = 3;
			break;
		case 1:
			dir = 2;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		default:
			break;
		}
	}
}

// Enable the animal moving and randomize a new direction
void Owl::move()
{
	this->moving = true;
	this->dir = std::rand() % 4;
}
