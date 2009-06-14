#include "GameState.h"

GameState* gameState;

GameState::GameState()
{
	gameState = this;
}

void updateDelegate()
{
	gameState->updateFunction();
}

