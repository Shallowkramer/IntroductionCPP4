#include "Cat.h"
#include <iostream>

Cat::Cat()
{
}

Cat::~Cat()
{
	//don't need anything here because no dynamic memory is allocated
}

void Cat::Description() const
{
	if (isPurring)
	{
		std::cout << "Wow it's a cat it's purring" << std::endl;
	}
	else
	{
		std::cout << "wow it's a car it's not purring" << std::endl;
	}
}

void Cat::Use()
{
	std::cout << "You pet the cat it seemed to ";

	if (isPurring)
	{
		std::cout << "not like it" << std::endl;
		isPurring = false;
	}
	else
	{
		std::cout << "like it" << std::endl;
		isPurring = true;
	}
}
