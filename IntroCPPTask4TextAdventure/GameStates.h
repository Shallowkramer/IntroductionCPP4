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
	virtual void Run(); //runs anything needed in the game state
	virtual void Draw(); //draws anything needed for the game state
};

