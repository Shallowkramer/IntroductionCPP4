#pragma once
#include <vector>
#include "Room.h"

class MyString;


class Player
{
public:
	//Functions
	Player();
	~Player();

	void CastSpell(MyString& spell);

private:
	//Variables

	std::vector<MyString> newSpellBook;

	//Functions
	
	void ExecuteSpell(MyString& spell);
	

	
};

