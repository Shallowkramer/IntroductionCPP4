#include "GameApplication.h"
#include "PlayState.h"

GameApplication::GameApplication()
{

}

GameApplication::~GameApplication()
{
	delete currentGameState;
}

void GameApplication::Run()
{
	//TODO make a game menu

	ChangeState(EGameState::PLAY);

	while (!shouldExit == false)
	{
		ChangeToNextState();

		currentGameState->Update();
	}
}

void GameApplication::Quit()
{
	shouldExit = true;
}

void GameApplication::ChangeState(EGameState newState)
{
	nextState = newState;
}

void GameApplication::ChangeToNextState()
{
	if (nextState == EGameState::NONE)
	{
		return;
	}
	if (currentGameState != nullptr)
	{
		currentGameState->Unload();
		delete currentGameState;
	}

	switch (nextState)
	{
	case EGameState::MENU:
	
		//current state will equal Menu state
		break;
	
		
	case EGameState::PLAY:
	
		currentGameState = new PlayState();
		break;
	
		
	case EGameState::GAMEOVER:
	
		//current state will equal gameover state
		break;
	
		
	case EGameState::CREDITS:
	
		//current state will equal credits state
		break;
	

	default:
	
		break;
	
		
	}
	currentGameState->Load();

	nextState = EGameState::NONE;
}




