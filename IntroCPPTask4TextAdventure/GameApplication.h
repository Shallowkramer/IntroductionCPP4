#pragma once

#include "GameStates.h"

class GameApplication
{
public:
	GameApplication();
	~GameApplication();

	void ChangeState(EGameState newstate);
	void ChangeToNextState();

	void Quit();

private:
	GameStates* currentGameState = nullptr;
	EGameState nextState = EGameState::NONE;

	bool shouldExit = false;
};

