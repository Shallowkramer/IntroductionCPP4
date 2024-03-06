#pragma once
#include "GameStates.h"
class PlayState : public GameStates
{
public:
	PlayState();
	~PlayState();

	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
};

