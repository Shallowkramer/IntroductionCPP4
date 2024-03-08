#pragma once
class MyString;
class Item;

enum class Items
{
	Empty,
	Lamp,
	BoxOfDonuts,
	Cat,
	Dog
};


class Room
{
public:
	//functions
	Room();
	~Room();

	void SetUp(Items itemIn);

	//TODO figure out out new system to say what's in the room
	void SetUp(int i);

	void Description() const;

	//variables
	Item* item = nullptr;

private:
	MyString* description = nullptr;

};

