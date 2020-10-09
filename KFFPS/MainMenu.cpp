#include "MainMenu.h"

MainMenu::MainMenu(unsigned int& screenWidth, unsigned int& screenHeight, GameState* gameState) :
	shader("shaders/sprite.vert", "shaders/sprite.frag"),
	screenWidth(screenWidth),
	screenHeight(screenHeight)
{
	this->gameState = gameState;
	this->renderSprite = new RenderSprite();
	this->projectionMat4 = glm::ortho(0.0f, static_cast<float>(this->screenWidth), static_cast<float>(this->screenHeight), 0.0f, -1.0f, 1.0f);

	this->shader.use();
	this->shader.setMat4("projection", this->projectionMat4);
}

MainMenu::~MainMenu()
{
	delete this->renderSprite;
}

void MainMenu::load()
{
	this->startTexture.load("assets/start.bmp", false);
	this->quitTexture.load("assets/quit.bmp", false);
}

void MainMenu::render()
{
	switch (this->cursor) {
	case MainMenu::START:
		this->renderSprite->DrawSprite(this->startTexture, this->shader, glm::vec2(100, 100), glm::vec2(320, 64), this->menuItemRotation, this->selectedColour);
		this->renderSprite->DrawSprite(this->quitTexture, this->shader, glm::vec2(100, 200), glm::vec2(320, 64), this->menuItemRotation, this->unselectedColour);
		break;
	case MainMenu::QUIT:
		this->renderSprite->DrawSprite(this->startTexture, this->shader, glm::vec2(100, 100), glm::vec2(320, 64), this->menuItemRotation, this->unselectedColour);
		this->renderSprite->DrawSprite(this->quitTexture, this->shader, glm::vec2(100, 200), glm::vec2(320, 64), this->menuItemRotation, this->selectedColour);
		break;
	}
}

void MainMenu::CursorDown()
{
	if (this->cursor + 1 >= 2) {
		this->cursor = MainMenu::QUIT;
	}
	else {
		this->cursor = this->cursor + 1;
	}
}

void MainMenu::CursorUp()
{
	if (this->cursor - 1 <= -1) {
		this->cursor = MainMenu::START;
	}
	else {
		this->cursor = this->cursor - 1;
	}
}

void MainMenu::accessMenu()
{
	switch (this->cursor) {
	case MainMenu::START:
		this->gameState->transitionToLoadGame();
		break;
	case MainMenu::QUIT:
		this->gameState->transitionToDnitShutdown();
		break;
	}
}
