#include "Animal.h"

Location Animal::getLocation() const
{
	return location;
}

// Disables the animal movement
void Animal::stop()
{
	this->moving = false;
}

// Enables the animal movement
void Animal::move()
{
	this->moving = true;
}
