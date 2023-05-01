#include "Monkey.h"

// Vector to represent the possible steps for owl
const std::vector<Location> Monkey::dirSteps = {
	Location(-1, 0),
	Location(1, 0),
	Location(0, -1),
	Location(0, 1)
};

void Monkey::printDetails() const
{
	std::cout << "Name: " << this->name << std::endl << "Type: Monkey\nLocation: " << this->location << std::endl;
}

char Monkey::getInitial() const
{
	return 'M';
}

// Make an owl step
void Monkey::step()
{ 
	if (!moving)
		return;
	for (int i = 0; i < stepSize; i++)
		this->location += dirSteps[dir];
	
	// update the turns counter and change direction when needed
	turn++;
	if (turn == 5)
	{
		reassignSteps();
		turn = 0;
	}

	// If any step is exceeding the board - 
	// fix location to be the closest location inside the board
	if (this->location.col < 0) {
		turnHorizontally();
		location.col = 0;
	}
	else if (this->location.col >= 40) {
		turnHorizontally();
		location.col = 40;
	}
	if (this->location.row < 0) {
		turnVertically();
		location.row = 0;
	}
	else if (this->location.row >= 20) {
		turnVertically();
		location.row = 0;
	}
}

// Turn up or down in the opposite direction to the current direction
void Monkey::turnVertically()
{
	switch (dir)
	{
	case 0:
		dir = 1;
		break;
	case 1:
		dir = 0;
		break;
	default:
		break;
	}
}

// Turn left or right in the opposite direction to the current direction
void Monkey::turnHorizontally() {
	switch (dir)
	{
	case 2:
		dir = 3;
		break;
	case 3:
		dir = 2;
		break;
	default:
		break;
	}
}

// Randomize new direction and new number of steps
void Monkey::reassignSteps()
{
	dir = (std::rand() % 4);
	stepSize = (std::rand() % 2) + 1;
}


