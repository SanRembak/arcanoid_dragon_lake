#include "Game.h"

void Game::PreInit(int& width, int& height, bool& fullscreen)
{
	width = 800;
	height = 600;
	fullscreen = false;
}

bool Game::Init()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	_brickCount = 8;
	_ballsCount = 3;

	Vector2 screenSize;
	getScreenSize(screenSize.x, screenSize.y);

	screenSize.x /= 2;
	screenSize.y = screenSize.y - screenSize.y / 4;

	_platform = new Platform(screenSize, 0.3);

	InitBricks();
	InitBalls();
	InitRandomBuff();

	return true;
}

void Game::Close() {

}

bool Game::Tick() {
	drawTestBackground();

	_platform->Draw();

	if (!_ability->isUsed)
	{
		_ability->Draw();
		_ability->Fly();
		_ability->HandleCollisionWithPlatform(_platform);
	}

	_isBallsAlive = false;
	for (int j = 0; j < _ballsCount; j++)
	{
		if (!_balls[j]._isAlive) continue;

		_isBallsAlive = true;
		_balls[j].Draw();

		if (!_balls[j].isLaunched)
		{
			Vector2Float ballSize = _balls[j].GetSize();
			Vector2Float ballPos = _platform->GetCenterPos() + Vector2Float(-1 * ballSize.x * 0.5, -1 * ballSize.y * 1.5);
			_balls[j].SetPos(ballPos);

			if (_isGameStarted && (!_ballLaunchDelay.IsStarted() || _ballLaunchDelay.IsComplete()))
			{
				LaunchingBalls(j);
			}

			continue;
		}

		_balls[j].Fly();

		_isBricksAlive = false;
		for (int i = 0; i < _brickCount; i++)
		{
			if(_bricks[i].IsAlive())
				_balls[j].HandleCollisionWithObject(&_bricks[i]);
		}

		_balls[j].HandleCollisionWithObject(_platform);
	}

	for (int i = 0; i < _brickCount; i++)
	{
		if (!_bricks[i].IsAlive()) continue;

		_isBricksAlive = true;
		_bricks[i].Draw();
	}


	return CheckWinLoseCondition();
}

void Game::onMouseMove(int x, int y, int xrelative, int yrelative) {
	_currentMousePos.x = x;
	_currentMousePos.y = y;
}

void Game::onMouseButtonClick(FRMouseButton button, bool isReleased) {

	if (button == FRMouseButton::LEFT && !_isGameStarted && isReleased)
	{
		_launchedBallPos = _currentMousePos;
		_isGameStarted = true;
	}
}

void Game::onKeyPressed(FRKey k) {
	_platform->HandleKey(k);
}

void Game::onKeyReleased(FRKey k) {
}

void Game::InitBricks()
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

void Game::InitBalls()
{
	Vector2 screenSize, ballSize;
	Vector2Float ballPos;
	getScreenSize(screenSize.x, screenSize.y);

	_balls = new Ball[_ballsCount]();

	for (int i = 0; i < _ballsCount; i++)
	{
		_balls[i].SetScale(1);
		ballSize = _balls[i].GetSize();
		ballPos = _platform->GetCenterPos() + Vector2Float(-1 * ballSize.x * 0.5, -1 * ballSize.y * 1.5);
		_balls[i].SetPos(ballPos);
	}
}

void Game::InitRandomBuff()
{
	const char* sprite = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\abilities\\a_width+.png";

	Vector2 screenSize, spriteSize;
	getScreenSize(screenSize.x, screenSize.y);
	_ability = new Ability(SizeBuff(), sprite, Vector2(0,0), 0.2);

	spriteSize = _ability->GetSize();
	_ability->SetPos(Vector2Float(screenSize.x / 2 - spriteSize.x / 2, screenSize.y / 2 - spriteSize.y / 2));
}

void Game::LaunchingBalls(int index)
{
	_ballLaunchDelay = Timer(1);

	Vector2Float directionVector = _launchedBallPos - _balls[index].GetPos();
	Vector2Float normalVector = directionVector.normal();

	if (normalVector.y > 0)
		normalVector *= -1;

	_ballLaunchDelay.Start();
	_balls[index].SetVelocity(normalVector);
	_balls[index].isLaunched = true;
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

	else if (!_isBallsAlive)
	{
		cout << "YOU LOSE" << endl;
		return true;
	}

	return false;
}

void Game::LaunchBall(Vector2Float to)
{
	using namespace std;

	//Vector2Float directionVector = to - _ball->GetPos();
	//Vector2Float normalVector = directionVector.normal();

	//if (normalVector.y > 0)
	//	normalVector *= -1;

	//_ball->SetVelocity(normalVector);
	//_platform->ball = NULL;

	_isGameStarted = true;
}

const char* Game::GetTitle()
{
	return "Arcanoid";
}