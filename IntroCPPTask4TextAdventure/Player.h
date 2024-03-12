#pragma once
#include <vector>

class MyString;


class Player
{
public:
	//Functions
	Player();
	~Player();

	bool FindSpell(MyString spell);

	void AddNewSpell(const char* newSpell, int insertAt);

private:
	//Variables
	int numberOfSpellStartLetter[26];

	std::vector<MyString> spells;

	//Functions
	void StarterSpells();
	
	void FindSpellInRange(int currentLetter);
	int FindSpellInRangeStart(int currentLetter);

	

	
};

