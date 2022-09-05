#include "Game.h"
#include <string>

void Game::PreInit(int& width, int& height, bool& fullscreen)
{
	width = 800;
	height = 600;
	fullscreen = false;
}

bool Game::Init() 
{
	return true;
}

void Game::Close() {

}

bool Game::Tick() {
	drawTestBackground();
	return false;
}

void Game::onMouseMove(int x, int y, int xrelative, int yrelative) {

}

void Game::onMouseButtonClick(FRMouseButton button, bool isReleased) {

}

void Game::onKeyPressed(FRKey k) {

}

void Game::onKeyReleased(FRKey k) {
}

const char* Game::GetTitle()
{
	return "Arcanoid";
}