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
	void Description() const;

	//variables
	Item* item = nullptr;

private:
	MyString* description = nullptr;

};

