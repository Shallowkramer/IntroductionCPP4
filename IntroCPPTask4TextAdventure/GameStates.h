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
	virtual void Load(); 
	virtual void Update(); //runs anything needed in the game state
	virtual void Draw(); //draws anything needed for the game state
	virtual void Unload(); //Will call deconstructor of any gamestates which will unload that gamestate
};

