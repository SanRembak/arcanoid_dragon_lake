#include "Game.h"

void Game::PreInit(int& width, int& height, bool& fullscreen)
{
	width = 800;
	height = 600;
	fullscreen = false;
}

bool Game::Init()
{
	_brickCount = 8;

	Vector2 screenSize;
	getScreenSize(screenSize.x, screenSize.y);

	Bricks();

	screenSize.x /= 2;
	screenSize.y = screenSize.y - screenSize.y / 4;

	_platform = new Platform(screenSize, 0.3);
	_ball = new Ball(screenSize - Vector2(0, _platform->GetSize().y), 1);

	_platform->ball = _ball;

	return true;
}

void Game::Close() {

}

bool Game::Tick() {
	drawTestBackground();

	_platform->Draw();
	_ball->Draw();

	_ball->Fly();

	_isBricksAlive = false;
	for (int i = 0; i < _brickCount; i++)
	{
		if (!_bricks[i].IsAlive()) continue;

		_isBricksAlive = true;
		_bricks[i].Draw();
		_ball->HandleCollisionWithObject(&_bricks[i]);
	}

	_ball->HandleCollisionWithObject(_platform);


	return false; //CheckWinLoseCondition();
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

void Game::Bricks()
{
	Vector2Float startPos = Vector2Float(100, 100);

	_bricks = new Brick[_brickCount]();

	for (int i = 0; i < _brickCount; i++)
	{
		_bricks[i].SetScale(0.2);
		Vector2 size = _bricks[i].GetSize();
		_bricks[i].ChangePosition(startPos + Vector2Float((size.x) * i, 0));
	}
}

bool Game::CheckWinLoseCondition()
{
	int x, y;
	getScreenSize(x, y);

	if (!_isBricksAlive)
	{
		cout << "YOU WIN!" << endl;
		return true;
	}
	
	else if (_ball->GetCenterPos().y >= y)
	{
		cout << "YOU LOSE" << endl;
		return true;
	}

	return false;
}

void Game::LaunchBall(Vector2Float to)
{
	using namespace std;

	Vector2Float directionVector = to - _ball->GetPos();
	Vector2Float normalVector = directionVector.normal();

	if (normalVector.y > 0)
		normalVector *= -1;

	_ball->SetVelocity(normalVector);
	_platform->ball = NULL;

	_isGameStarted = true;
}

const char* Game::GetTitle()
{
	return "Arcanoid";
}