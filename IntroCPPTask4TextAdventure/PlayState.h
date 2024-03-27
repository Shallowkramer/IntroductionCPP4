#pragma once
#include "GameStates.h"
#include "Vec2.h"
#include "MyString.h"

class Room;
class Player;
class MyString;

class PlayState : public GameStates
{
public:
	PlayState();
	~PlayState();

	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;

private:
	//Variables
	Room** rooms; //dynamic 2D array of rooms
	Player* player;
	
	int rows = 5;
	int columns = 5;

	int playerPosX;
	int	playerPosY;

	MyString userInput;

	//Functions
	void TryMove(char c);
	void TryUse(char c);
	void TryInspect(char c);

	
};

