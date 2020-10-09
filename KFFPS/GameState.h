#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>

class GameState
{


public:
	GameState();
	~GameState();
	static const int INIT_SYSTEMS = 0;
	static const int LOAD_MAIN_MENU = 1;
	static const int RNDR_MAIN_MENU = 2;
	static const int LOAD_GAME = 3;
	static const int RNDR_GAME = 4;
	static const int LOAD_PAUSE_MENU = 5;
	static const int RNDR_PAUSE_MENU = 6;
	static const int DNIT_SHUTDOWN = 7;
	int state();
	void transitionToInitSystems();
	void transitionToLoadMainMenu();
	void transitionToRndrMainMenu();
	void transitionToLoadGame();
	void transitionToRndrGame();
	void transitionToDnitShutdown();
private:
	int curState = GameState::INIT_SYSTEMS;
};

#endif