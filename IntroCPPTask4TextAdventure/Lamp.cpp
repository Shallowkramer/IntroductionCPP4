#include "Lamp.h"
#include <iostream>

Lamp::Lamp()
{ 

}

Lamp::~Lamp()
{
	//don't need anything here because no dynamic memory is allocated
}

void Lamp::Description() const
{
	if (turnedOn)
	{
		std::cout << "Not much to say about this lamp, but it is on" << std::endl;
	}
	else
	{
		std::cout << "Not much to say about this lamp..." << std::endl;
	}
}

void Lamp::Use()
{
	turnedOn = !turnedOn;

	std::cout << "You flick the switch on the lamp and turned it";

	if (turnedOn)
	{
		std::cout << "on" << std::endl;
	}
	else
	{
		std::cout << "off" << std::endl;
	}
}
