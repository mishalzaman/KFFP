#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <glm/glm.hpp>
#include "Texture2d.h"
#include "RenderSprite.h"
#include "Shader.h"
#include "KeyInput.h"
#include "GameState.h"

class MainMenu
{
public:
	MainMenu(unsigned int& screenWidth, unsigned int& screenHeight, GameState* gameState);
	~MainMenu();
	void load();
	void render();
	void CursorDown();
	void CursorUp();
	void accessMenu();
private:
	const static int START			= 0;
	const static int QUIT			= 1;
	GameState*						gameState;
	Shader							shader;
	RenderSprite*					renderSprite;
	Texture2d						startTexture;
	Texture2d						quitTexture;
	unsigned int					screenWidth;
	unsigned int					screenHeight;
	glm::mat4						projectionMat4;
	int cursor						= MainMenu::START;
	float menuItemRotation			= 0.0f;
	glm::vec3 unselectedColour		= glm::vec3(1.0f);
	glm::vec3 selectedColour		= glm::vec3(1.0f, 0.0f, 0.0f);
};

#endif

