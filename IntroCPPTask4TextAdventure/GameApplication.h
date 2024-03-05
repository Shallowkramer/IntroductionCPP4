#pragma once

#include "GameStates.h"

class GameApplication
{
public:
	GameApplication();
	~GameApplication();

	void Run();
	void Quit();

	void ChangeState(EGameState newState);
	void ChangeToNextState();

private:
	GameStates* currentGameState = nullptr;
	EGameState nextState = EGameState::NONE;

	bool shouldExit = false;
};

