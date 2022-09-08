#pragma once
#include <vector>
#include "Framework.h"
#include "Platform.h"
#include "Ball.h"
#include "Brick.h"

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

	void Bricks();
	static int RandomRange(int from, int to) { return from + (std::rand() % (to - from + 1)); }

	bool CheckWinLoseCondition();
private:
	Vector2Float _currentMousePos;

	Brick* _bricks;
	int _brickCount;

	Platform* _platform;
	Ball* _ball;

	bool _isBricksAlive;
	bool _isGameStarted;
	bool _isWon;

	void LaunchBall(Vector2Float to);
};