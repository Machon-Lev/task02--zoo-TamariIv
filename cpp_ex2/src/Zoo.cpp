#include "Zoo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>

Location Zoo::randomizeLocation()
{
	return Location((std::rand() % 21), (std::rand() % 41));
}

void Zoo::initializeZoo()
{
	this->create("Simba", "Lion");
	this->create("Mufasa", "Lion");
	this->create("Rafiki", "Monkey");
	this->create("Hedwig", "Owl");
}

bool Zoo::compareByLocation(const Animal* a1, const Animal* a2)
{
	if (a1->getLocation().row == a2->getLocation().row)
		return a1->getLocation().col < a2->getLocation().col;
	return a1->getLocation().row < a2->getLocation().row;
}

int Zoo::getCommand() const
{
	std::string command;
	std::cout << "Enter a command: ";
	std::cin >> command;
	if (command == ".")
		return STEP;
	else if (command == "stop")
		return STOP;
	else if (command == "move")
		return MOVE;
	else if (command == "create")
		return CREATE;
	else if (command == "del")
		return DEL;
	else if (command == "delAll")
		return DEL_ALL;
	else if (command == "help")
		return HELP;
	else if (command == "exit")
		return EXIT;
	else
		return -1;
}

bool Zoo::validType(std::string type) const
{
	std::vector<std::string> types = { "Lion", "Owl", "Monkey" };
	return std::find(types.begin(), types.end(), type) != types.end();
}

bool Zoo::validId(int id) const
{
	return id < animalsList.size() && id >= 0;
}



void Zoo::run()
{
	std::cout << "Enter . to make a step\n\
Enter 'stop' to stop an animal\n\
Enter 'move' to let animal move\n\
Enter 'create' to create a new animal\n\
Enter 'del' to remove an animal\n\
Enter 'delAll' to remove a specific type of animals\n\
Enter 'help' to get help\n\
Enter 'exit' to finish the game\n";
	this->printList();
	this->printMap();

	int command = getCommand();
	std::string type, name;
	int id;
	while (true)
	{
		switch (command)
		{
		case STEP:
			this->step();
			break;
		case STOP:
			std::cout << "Enter animal ID number: " << std::endl;
			std::cin >> id;
			if (!validId(id)) {
				std::cout << "Invalid animal id\n";
				break;
			}
			this->stop(id);
			break;
		case MOVE:
			std::cout << "Enter animal ID number: " << std::endl;
			std::cin >> id;
			if (!validId(id)) {
				std::cout << "Invalid animal id\n";
				break;
			}
			this->move(id);
			break;
		case CREATE:
			std::cout << "Enter new animal type: " << std::endl;
			std::cin >> type;
			if (!validType(type)) {
				std::cout << "Invalid animal type\n";
				break;
			}
			std::cout << "Enter new animal name: " << std::endl;
			std::cin >> name;
			this->create(name, type);
			break;
		case DEL:
			std::cout << "Enter animal ID number: " << std::endl;
			std::cin >> id;
			if (!validId(id)) {
				std::cout << "Invalid animal id\n";
				break;
			}
			this->del(id);
			break;
		case DEL_ALL:
			std::cout << "Enter animal type: " << std::endl;
			std::cin >> type;
			if (!validType(type)) {
				std::cout << "Invalid animal type\n";
				break;
			}
			this->delAll(type);
			break;
		case HELP:
			this->help();
			break;
		case EXIT:
			return;
		default:
			std::cout << "Invalid command" << std::endl;
			break;
		}
		this->printList();
		this->printMap();
		command = getCommand();
	}

}

void Zoo::move(int idx)
{
	animalsList[idx]->move();
}

void Zoo::stop(int idx)
{
	animalsList[idx]->stop();
}

void Zoo::create(std::string name, std::string type)
{
	Animal* animal;
	if (type == "Lion")
		animal = new Lion(name, this->randomizeLocation());
	else if (type == "Owl")
		animal = new Owl(name, this->randomizeLocation());
	else if (type == "Monkey")
		animal = new Monkey(name, this->randomizeLocation());
	else
		return;
	animalsList.push_back(animal);
}

void Zoo::del(int idx)
{
	animalsList[idx]->~Animal();
	animalsList.erase(animalsList.begin() + idx);
}

void Zoo::delAll(std::string type)
{
	if (type == "Lion") {
		for (int i = 0; i < animalsList.size(); i++) {
			if (typeid(*animalsList[i]) == typeid(Lion))
				del(i);
		}
	}
	else if (type == "Monkey")
	{
		for (unsigned i = 0; i < animalsList.size(); i++) {
			if (typeid(animalsList[i]) == typeid(Monkey))
				del(i);
		}
	}
	else if (type == "Owl") {
		for (unsigned i = 0; i < animalsList.size(); i++) {
			if (typeid(animalsList[i]) == typeid(Owl))
				del(i);
		}
	}
}

void Zoo::help()
{
	std::cout << "Enter . to make a step. All the enabled animals will make one step.\n\
Enter 'move' to enable an animal moving. You will be asked to provide the animal number.\n\
Enter 'stop' to disable an animal from moving. You will be asked to provide the animal number.\n\
Enter 'create' to add a new animal to the zoo. You will be asked to provide the new animal name and type.\n\
Enter 'del' to remove an animal from the zoo. You will be asked to provide the animal number.\n\
Enter 'delAll' to remove all the animals of a certain type. You will be asked to provide the animal type.\n";
}

void Zoo::step()
{
	for (Animal* an : animalsList) {
		an->step();
	}
}

void Zoo::printMap()
{
	int animalIdx = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j <= 40; j++) {
			if (animalIdx < animalsList.size() && animalsList[animalIdx]->getLocation().row == i && animalsList[animalIdx]->getLocation().col == j) {
				std::cout << animalsList[animalIdx]->getInitial();
				animalIdx++;
			}
			else
				std::cout << "~";
		}
		std::cout << std::endl;
	}
}

void Zoo::printList()
{
	std::sort(animalsList.begin(), animalsList.end(), Zoo::compareByLocation);
	for (int i = 0; i < animalsList.size(); i++) {
		std::cout << "Animal " << i << ":" << std::endl;
		animalsList[i]->printDetails();
	}
}
