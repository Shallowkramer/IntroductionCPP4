#include "Dog.h"
#include <iostream>

Dog::Dog()
{

}

Dog::~Dog()
{
	//don't need anything here because no dynamic memory is allocated
}

void Dog::Description() const
{
	if (isDog)
	{
		std::cout << "\"Woof...I am definetly a dog...\". Did that dog just speak?" << std::endl;
	}
	else
	{
		std::cout << "\"Meow\". Did that dog just meow?" << std::endl;
	}
}

void Dog::Use()
{
	std::cout << "Somethings not right about that \'Dog\'..." << std::endl;
	isDog = !isDog;
}
