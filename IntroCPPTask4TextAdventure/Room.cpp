#include "Room.h"
#include "MyString.h"

//items
#include "Lamp.h"
#include "BoxOfDonuts.h"
#include "Cat.h"
#include "Dog.h"


Room::Room()
{

}

Room::~Room()
{
	delete item;
	delete description;
}

void Room::SetUp(Items itemIn)
{
	switch (itemIn)
	{
	case Items::Empty:
		this->item = nullptr;
		this->description = new MyString("The room is completely empty...");
		break;

	case Items::Lamp:
		this->item = new Lamp();
		this->description = new MyString("The room contains a lamp...");
		break;

	case Items::BoxOfDonuts:
		this->item = new BoxOfDonuts();
		this->description = new MyString("There is a box of donuts in the corner of the room...");
		break;

	case Items::Cat:
		this->item = new Cat();
		this->description = new MyString("You see a cat wandering around the room...");
		break;

	case Items::Dog:
		this->item = new Dog();
		this->description = new MyString("A dog sits in the middle of the room smiling at you...");
		break;

	default:
		this->item = nullptr;
		this->description = new MyString("How did we even get here");
		break;
	}
}

void Room::Description() const
{
	description->WriteToConsole();
}
