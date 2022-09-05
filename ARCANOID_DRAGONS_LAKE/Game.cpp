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
	_platform = new Platform(380, 400, 0.3);

	return true;
}

void Game::Close() {

}

bool Game::Tick() {
	drawTestBackground();
	_platform->Draw();
	return false;
}

void Game::onMouseMove(int x, int y, int xrelative, int yrelative) {

}

void Game::onMouseButtonClick(FRMouseButton button, bool isReleased) {

}

void Game::onKeyPressed(FRKey k) {
	_platform->HandleKey(k);
}

void Game::onKeyReleased(FRKey k) {
}

const char* Game::GetTitle()
{
	return "Arcanoid";
}