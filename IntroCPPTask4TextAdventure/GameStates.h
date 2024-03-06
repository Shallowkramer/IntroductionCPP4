#pragma once
class MyString;

enum class EGameState
{
	NONE,
	MENU,
	PLAY,
	GAMEOVER,
	CREDITS
};

class GameStates
{
public:
	virtual void Load() = 0; //loads anything needed for the game state
	virtual void Update() = 0; //Updates anything needed in the game state
	virtual void Draw() = 0; //draws anything needed for the game state
	virtual void Unload() = 0; //Will call deconstructor of any gamestates which will unload that gamestate
};

