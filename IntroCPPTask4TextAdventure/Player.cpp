#include "Player.h"
#include "MyString.h"
#include <vector>
#include <algorithm>
#include <iostream>

Player::Player()
{
	newSpellBook.push_back("ignite");
	newSpellBook.push_back("heal");
	newSpellBook.push_back("freeze");
	
}

Player::~Player()
{
	
}

void Player::CastSpell(MyString& spell)
{
	//length of spell book
	int spellbookLength = 3;


	std::sort(newSpellBook.begin(), newSpellBook.end());

	int l = 0;

	int r = spellbookLength - 1;

	
	while (true)
	{
		int middle = (l + r) / 2;

		if (newSpellBook[middle] == spell)
		{
			ExecuteSpell(spell);
			break;
		}
		else if (newSpellBook[middle] < spell)
		{
			l = middle + 1;
		}
		else
		{
			r = middle - 1;
		}
	}
}

void Player::ExecuteSpell(MyString& spell)
{
	if (spell.EqualTo("ignite"))
	{
		std::cout << "You cast ignite" << std::endl;
	}
	else if (spell.EqualTo("heal"))
	{
		std::cout << "You cast heal" << std::endl;
	}
	else if (spell.EqualTo("freeze"))
	{
		std::cout << "You cast freeze" << std::endl;
	}
}

