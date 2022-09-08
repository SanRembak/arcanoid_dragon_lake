#pragma once
#include <cstdlib>
#include <ctime>
#include "Framework.h"
#include "Platform.h"
#include "Ball.h"
#include "Brick.h"
#include "Timer.h"
#include "Ability.h"
#include "SizeBuff.h"

//So I didn't complete two additional features
// First stackable buff, it's almost done, but I was stucked with undefined type error, I was like confused here
// Second it's every 20 sec spawn ability in the middle of screen, i have Timer class so it's easy to finish that task
// And I didn't complete comand line, but I think it's also easy, i can just set scale and change position little bit

class Timer;
using namespace std;

class Game : public Framework {

public:

	virtual const char* GetTitle() override;
	virtual void PreInit(int& width, int& height, bool& fullscreen);

	virtual bool Init();
	virtual void Close();
	virtual bool Tick();

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
	virtual void onKeyPressed(FRKey k);
	virtual void onKeyReleased(FRKey k);

	void InitBricks();
	void InitBalls();
	void InitRandomBuff();

	void LaunchingBalls(int index);
	//void HandleBallDestroing();

	static int RandomRange(int min, int max) 
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	bool CheckWinLoseCondition();
private:
	Vector2Float _currentMousePos;
	Vector2Float _launchedBallPos;

	Ability* _ability;

	Brick* _bricks;
	int _brickCount;

	Platform* _platform;

	Ball* _balls;
	int _ballsCount;

	bool _isBricksAlive;
	bool _isBallsAlive;
	bool _isGameStarted;
	bool _isWon;

	Timer _ballLaunchDelay;

	void LaunchBall(Vector2Float to);
};