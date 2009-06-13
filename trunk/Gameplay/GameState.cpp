#include "GameState.h"

GameState* gameState;

GameState::GameState()
{
	gameState = this;
}

/*
 * causing some undefined reference errors
 *
void updateDelegate()
{
	gameState->updateState();
}

void GameState::updateState()
{

}
*/
