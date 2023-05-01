// cpp_ex2.cpp : Defines the entry point for the application.
//

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Zoo.h"



int main() {

	std::srand(std::time(nullptr));
	Zoo* zoo = new Zoo();
	zoo->run();


	return 0;
}

