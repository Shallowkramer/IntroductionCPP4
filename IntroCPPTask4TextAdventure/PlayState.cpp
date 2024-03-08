#include "PlayState.h"

#include "MyString.h"
#include "Room.h"
#include "Player.h"
#include "BoxOfDonuts.h"
#include "Cat.h"
#include "Dog.h"
#include "Lamp.h"
#include <iostream>

PlayState::PlayState()
{
	Load();
}

PlayState::~PlayState()
{
	Unload();
}

void PlayState::Load()
{
	userInput = new MyString();

	player = new Player();

	rooms = new Room * [rows];

	for (int i = 0; i < columns; i++)
	{
		rooms[i] = new Room[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			rooms[i][j].SetUp((((i + 2) * 80) + ((j + 7) * 16)) % 5);
		}
	}

	playerPosX = 2;
	playerPosY = 2;
}

void PlayState::Update()
{
	Draw();
	//TODO:
	//Room should print its description
	//Ask the user for an action/input
	//Parse through input 
	//Run logic according to what I find
	//Affect game data accordingly

	rooms[playerPosY][playerPosX].Description();

	std::cout << "What would you like to do now? (move / use <item> / inspect <item>)" << std::endl;

	userInput->ReadFromConsole();

	userInput->ToLower();

	//Parsing and According Logic
	switch (userInput->CharacterAt(0))
	{
	case'm': //player trying to move
		if (userInput->Find("move") != -1)
		{
			if (userInput->Find("north") != -1)
			{
				//Move player north
				TryMove('n');
			}
			else if (userInput->Find("south") != -1)
			{
				//Move player south
				TryMove('s');
			}
			else if (userInput->Find("east") != -1)
			{
				//Move player east
				TryMove('e');
			}
			else if (userInput->Find("west") != -1)
			{
				//Move player west
				TryMove('w');
			}
			else
			{
				std::cout << "Couldn't figure out how you wanted to move..." << std::endl;
			}
		}
		
	case'u': //player trying to use
		if (userInput->Find("use") != -1)
		{
			if (userInput->Find("lamp") != -1)
			{
				TryUse('l');
			}
			else if (userInput->Find("box of donuts") != -1)
			{
				TryUse('b');
			}
			else if (userInput->Find("cat") != -1)
			{
				TryUse('c');
			}
			else if (userInput->Find("dog") != -1)
			{
				TryUse('d');
			}
			else
			{
				std::cout << "Couldn't figure out what you were trying to use..." << std::endl;
			}
		}
		break;

	case'i': //player trying to inspect something
		if (userInput->Find("inspect") != -1)
		{
			if (userInput->Find("lamp") != -1)
			{
				TryInspect('l');
			}
			else if (userInput->Find("box of donuts") != -1)
			{
				TryInspect('b');
			}
			else if (userInput->Find("cat") != -1)
			{
				TryInspect('c');
			}
			else if (userInput->Find("dog") != -1)
			{
				TryInspect('d');
			}
			else
			{
				std::cout << "Couldn't figure out what you were trying to inspect..." << std::endl;
			}
		}
		break;

	default:
		std::cout << "What were you even trying to say???" << std::endl;
		break;
	}

	system("pause");
}

void PlayState::Draw()
{
	//TODO:
	//Draw a basic layout of the players current position inside m_rooms

	system("cls"); //clear console of any and all text

	std::cout << "\n\n----------------------------------------\n\n";



	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{

			std::cout << "| ";

			if (i == playerPosY && j == playerPosX)
			{
				//draw player
				std::cout << "P";
			}
			else
			{
				//draw room
				std::cout << "_";
			}

			std::cout << " |";

		}
		std::cout << std::endl << "\n";
	}


	std::cout << "\n\n----------------------------------------\n\n";
}

void PlayState::Unload()
{
	delete userInput;
	delete player;

	for (int i = 0; i < columns; i++)
	{
		delete[] rooms[i];
	}

	delete[] rooms;
}

void PlayState::TryMove(char c)
{
	switch (c)
	{
	case 'n':
		if (playerPosY >= 1)
		{
			playerPosY--;
			std::cout << "You moved north yaya!" << std::endl;
		}
		else
		{
			std::cout << "There were no paths to go north" << std::endl;
		}
		break;
	case 's':
		if (playerPosY < rows - 1)
		{
			playerPosY++;
			std::cout << "Huzzah you moved south!" << std::endl;
		}
		else
		{
			std::cout << "There were no paths to go south" << std::endl;
		}
		break;
	case 'e':
		if (playerPosX < columns - 1)
		{
			playerPosX++;
			std::cout << "You moved east wow!" << std::endl;
		}
		else
		{
			std::cout << "There were no paths to go east.." << std::endl;
		}
		break;
	case 'w':
		if (playerPosX >= 1)
		{
			playerPosX--;
			std::cout << "You moved west yippe!" << std::endl;
		}
		else
		{
			std::cout << "There were no paths to go west" << std::endl;
		}
		break;
	}
}

void PlayState::TryUse(char c)
{
	switch (c)
	{
	case 'b':
	{
		BoxOfDonuts* bod = dynamic_cast<BoxOfDonuts*>(rooms[playerPosY][playerPosX].item);
		if (bod != nullptr)
		{
			bod->Use();
		}
		else
		{
			std::cout << "There was nothing like that to use in the room..." << std::endl;
		}
		break;
	}
	case 'c':
	{
		Cat* cat = dynamic_cast<Cat*>(rooms[playerPosY][playerPosX].item);
		if (cat != nullptr)
		{
			cat->Use();
		}
		else
		{
			std::cout << "There was nothing like that to use in the room..." << std::endl;
		}
		break;
	}
	case 'l':
	{
		Lamp* lamp = dynamic_cast<Lamp*>(rooms[playerPosY][playerPosX].item);
		if (lamp != nullptr)
		{
			lamp->Use();
		}
		else
		{
			std::cout << "There was nothing like that to use in the room..." << std::endl;
		}
		break;
	}
	case 'd':
	{
		Dog* dog = dynamic_cast<Dog*>(rooms[playerPosY][playerPosX].item);
		if (dog != nullptr)
		{
			dog->Use();
		}
		else
		{
			std::cout << "There was nothing like that to use in the room..." << std::endl;
		}
		break;
	}
	default:
		std::cout << "There was nothing in the room to use..." << std::endl;
		break;
	}
}

void PlayState::TryInspect(char c)
{
	switch (c)
	{
	case 'b':
	{
		BoxOfDonuts* bod = dynamic_cast<BoxOfDonuts*>(rooms[playerPosY][playerPosX].item);
		if (bod != nullptr)
		{
			bod->Description();
		}
		else
		{
			std::cout << "There was nothing like that to use in the room..." << std::endl;
		}
		break;
	}
	case 'c':
	{
		Cat* cat = dynamic_cast<Cat*>(rooms[playerPosY][playerPosX].item);
		if (cat != nullptr)
		{
			cat->Description();
		}
		else
		{
			std::cout << "There was nothing like that to use in the room..." << std::endl;
		}
		break;
	}
	case 'l':
	{
		Lamp* lamp = dynamic_cast<Lamp*>(rooms[playerPosY][playerPosX].item);
		if (lamp != nullptr)
		{
			lamp->Description();
		}
		else
		{
			std::cout << "There was nothing like that to use in the room..." << std::endl;
		}
		break;
	}
	case 'd':
	{
		Dog* dog = dynamic_cast<Dog*>(rooms[playerPosY][playerPosX].item);
		if (dog != nullptr)
		{
			dog->Description();
		}
		else
		{
			std::cout << "There was nothing like that to use in the room..." << std::endl;
		}
		break;
	}
	default:
		std::cout << "There was nothing in the room to use..." << std::endl;
		break;
	}
}
