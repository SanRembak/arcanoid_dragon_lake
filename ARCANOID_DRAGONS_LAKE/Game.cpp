#include "Game.h"

void Game::PreInit(int& width, int& height, bool& fullscreen)
{
	width = 800;
	height = 600;
	fullscreen = false;
}

bool Game::Init()
{
	Vector2 screenSize;
	getScreenSize(screenSize.x, screenSize.y);

	screenSize.x /= 2;
	screenSize.y = screenSize.y - screenSize.y / 4;

	_platform = new Platform(screenSize, 0.3);
	_ball = new Ball(screenSize - Vector2(0, _platform->GetSize().y), 1);

	_platform->_ball = _ball;

	return true;
}

void Game::Close() {

}

bool Game::Tick() {
	drawTestBackground();

	_platform->Draw();
	_ball->Fly();
	_ball->Draw();

	return false;
}

void Game::onMouseMove(int x, int y, int xrelative, int yrelative) {
	_currentMousePos.x = x;
	_currentMousePos.y = y;
}

void Game::onMouseButtonClick(FRMouseButton button, bool isReleased) {

	if (button == FRMouseButton::LEFT && !_isGameStarted && isReleased)
	{
		LaunchBall(_currentMousePos);
	}
}

void Game::onKeyPressed(FRKey k) {
	_platform->HandleKey(k);
}

void Game::onKeyReleased(FRKey k) {
}

void Game::LaunchBall(Vector2Float to)
{
	using namespace std;

	Vector2Float directionVector = to - _ball->GetPos();
	Vector2Float normalVector = directionVector.normal();

	if (normalVector.y > 0)
		normalVector *= -1;

	_ball->SetVelocity(normalVector);

	_isGameStarted = true;
}

const char* Game::GetTitle()
{
	return "Arcanoid";
}