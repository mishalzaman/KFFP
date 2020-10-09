#include "GameState.h"

GameState::GameState()
{
}

GameState::~GameState()
{
}

int GameState::state()
{
	return this->curState;
}

void GameState::transitionToInitSystems()
{
	this->curState = GameState::INIT_SYSTEMS;
}

void GameState::transitionToLoadMainMenu()
{
	this->curState = GameState::LOAD_MAIN_MENU;
}

void GameState::transitionToRndrMainMenu()
{
	this->curState = GameState::RNDR_MAIN_MENU;
}

void GameState::transitionToLoadGame()
{
	this->curState = GameState::LOAD_GAME;
}

void GameState::transitionToRndrGame()
{
	this->curState = GameState::RNDR_GAME;
}

void GameState::transitionToDnitShutdown()
{
	this->curState = GameState::DNIT_SHUTDOWN;
}
