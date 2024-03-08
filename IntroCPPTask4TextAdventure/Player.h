#pragma once
#include <vector>

class MyString;


class Player
{
public:
	Player();
	~Player();

	bool FindSpell(MyString* spell);

private:
	std::vector<MyString*> spells; 
};

