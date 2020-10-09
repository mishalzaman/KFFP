#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Cfg_OpenGL.h"
#include "Cfg_SDL.h"
#include "KeyInput.h"
#include "GameState.h"
#include "MainMenu.h"

SDL_Window* window;
SDL_GLContext context;
unsigned int SCREEN_WIDTH = 1280;
unsigned int SCREEN_HEIGHT = 720;

int main(int argc, char* args[]) {
	/* -----------------
	 Core initialization
	-------------------*/
	unsigned int errCode = Cfg_SDL::defaults(
		window,			// SDL_Window*
		context,		// SDL_GLContext	
		SCREEN_WIDTH,   // max screen width
		SCREEN_HEIGHT,  // max screen height
		3,				// OpenGL minor version
		3,			    // OpenGL major version
		false			// Multisampling AA
	);

	if (errCode > 0) {
		return errCode;
	};

	Cfg_OpenGL::viewPort(SCREEN_WIDTH, SCREEN_HEIGHT);
	Cfg_OpenGL::glBlend();
	Cfg_OpenGL::glBlendFunAlpha();

	/* -----------------
	 Game Init
	-------------------*/
	KeyInput* input		 = new KeyInput();
	GameState* gameState = new GameState();
	MainMenu* mainMenu	 = new MainMenu(SCREEN_WIDTH, SCREEN_HEIGHT, gameState);

	gameState->transitionToLoadMainMenu();
	float deltaTime = 1.0f / 60.0f;

	/* -----------------
	 Game Loop
	-------------------*/
	while (gameState->state() != GameState::DNIT_SHUTDOWN) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		switch (gameState->state()) {
		case GameState::LOAD_MAIN_MENU:
			printf("Load the main menu\n");
			mainMenu->load();
			gameState->transitionToRndrMainMenu();
			break;
		case GameState::RNDR_MAIN_MENU:
			printf("Render the main menu\n");
			if (input->isW()) { mainMenu->CursorUp(); }
			if (input->isS()) { mainMenu->CursorDown(); }
			if (input->isD()) { mainMenu->accessMenu(); }

			mainMenu->render();
			break;
		case GameState::LOAD_GAME:
			printf("Load Game\n");
			gameState->transitionToRndrGame();
			break;
		case GameState::RNDR_GAME:
			printf("Render Game\n");

			if (input->isEsc()) {
				gameState->transitionToRndrMainMenu();
			}

			break;
		}

		input->update(deltaTime);

		SDL_GL_SwapWindow(window);
	}

	delete input;
	delete gameState;
	delete mainMenu;
	return 0;
}