#pragma once
#include <vector>
#include "Framework.h"
#include "Platform.h"
#include "Ball.h"
#include "Brick.h"
#include "Timer.h"

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

	void LaunchingBalls(int index);
	//void HandleBallDestroing();

	static int RandomRange(int from, int to) { return from + (std::rand() % (to - from + 1)); }

	bool CheckWinLoseCondition();
private:
	Vector2Float _currentMousePos;
	Vector2Float _launchedBallPos;

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