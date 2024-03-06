#include "BoxOfDonuts.h"
#include <iostream>

BoxOfDonuts::BoxOfDonuts()
{

}

BoxOfDonuts::~BoxOfDonuts()
{
	//don't need anything here because no dynamic memory is allocated
}

void BoxOfDonuts::Description() const
{
	std::cout << "This random box of donuts currently holds " << numberOfDonuts << " donut(s)" << std::endl;
}

void BoxOfDonuts::Use()
{
	if (0 < numberOfDonuts)
	{
		std::cout << "Why would you eat a random donut you found, either way you eat one..." << std::endl;
		numberOfDonuts--;
	}
	else
	{
		std::cout << "The box of donuts is now empty... how could you..." << std::endl;
	}
}
