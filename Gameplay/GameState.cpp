#include "GameState.h"

GameState* gameState;

GameState::GameState()
{
	gameState = this;
}

inline void updateDelegate()
{
	gameState->updateState();
}
