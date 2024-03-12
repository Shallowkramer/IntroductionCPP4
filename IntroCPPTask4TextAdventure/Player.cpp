#include "Player.h"
#include "MyString.h"
#include <vector>

Player::Player()
{
	StarterSpells();
	
}

Player::~Player()
{

}

bool Player::FindSpell(MyString spell)
{
	int spellBookSize = spells.size();
	int findSpellInRangeStart = 0;
	
	if (!spells.empty())
	{
		//checks the first letter of the spell attempting to be found
		//than whatever that letter starts with all spells with that start letter will be checked
		//eg if input was ants it would go to case 'a' and than search all spells that start with 'a'
		switch (spell[0])
		{
		case 'a':
			FindSpellInRange(0);
			break;

		case 'b':
			
			FindSpellInRange(1);
			break;

		case 'c':
			FindSpellInRange(2);
			break;

		case 'd':
			FindSpellInRange(3);
			break;

		case 'e':
			FindSpellInRange(4);
			break;

		case 'f':
			FindSpellInRange(5);
			break;

		case 'g':
			FindSpellInRange(6);
			break;

		case 'h':
			FindSpellInRange(7);
			break;

		case 'i':
			FindSpellInRange(8);
			break;

		case 'j':
			FindSpellInRange(9);
			break;

		case 'k':
			FindSpellInRange(10);
			break;

		case 'l':
			FindSpellInRange(11);
			break;

		case 'm':
			FindSpellInRange(12);
			break;

		case 'n':
			FindSpellInRange(13);
			break;

		case 'o':
			FindSpellInRange(14);
			break;

		case 'p':
			FindSpellInRange(15);
			break;

		case 'q':
			FindSpellInRange(16);
			break;

		case 'r':
			FindSpellInRange(17);
			break;

		case 's':
			FindSpellInRange(18);
			break;

		case 't':
			FindSpellInRange(19);
			break;

		case 'u':
			FindSpellInRange(20);
			break;

		case 'v':
			FindSpellInRange(21);
			break;

		case 'w':
			FindSpellInRange(22);
			break;

		case 'x':
			FindSpellInRange(23);
			break;

		case 'y':
			FindSpellInRange(24);
			break;

		case 'z':
			FindSpellInRange(25);
			break;

		default:
			break;
		}
	}

	return false;
}

void Player::AddNewSpell(const char* newSpell, int insertAt)
{
	//TODO organise newSpell so that all spells are organised alphabetically
	MyString tempString(newSpell);

	spells.push_back(tempString);
}

void Player::StarterSpells()
{
	for (int i = 0; i < 26; i++)
	{
		numberOfSpellStartLetter[i] = 1;
	}

	AddNewSpell("ants", 0);

	AddNewSpell("bees", 1);

	AddNewSpell("cat", 2);

	AddNewSpell("dog", 3);

	AddNewSpell("elephant", 4);

	AddNewSpell("flys", 5);

	AddNewSpell("goodnight", 6);

	AddNewSpell("helicopter", 7);

	AddNewSpell("int", 8);

	AddNewSpell("jerry", 9);

	AddNewSpell("kick", 10);

	AddNewSpell("lollie", 11);

	AddNewSpell("master", 12);

	AddNewSpell("nasty", 13);

	AddNewSpell("octopus", 14);

	AddNewSpell("pilot", 15);

	AddNewSpell("quack", 16);

	AddNewSpell("ants", 17);

	AddNewSpell("silo", 18);

	AddNewSpell("title", 19);

	AddNewSpell("ultra", 20);

	AddNewSpell("violet", 21);

	AddNewSpell("winner", 22);

	AddNewSpell("xenon", 23);

	AddNewSpell("yield", 24);

	AddNewSpell("zen", 25);

}

void Player::FindSpellInRange(int currentLetter)
{
	int start = FindSpellInRangeStart(currentLetter);
	int amountOfSpellsContainedInFirstLetter = numberOfSpellStartLetter[currentLetter];
}

int Player::FindSpellInRangeStart(int currentLetter)
{
	int startNumber = 0;

	for (int i = 0; i < 26; i++)
	{
		startNumber = numberOfSpellStartLetter[i];
	}

	return startNumber;
}
