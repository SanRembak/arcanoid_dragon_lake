#pragma once
#include "Framework.h"
#include "MovableObject.h"
#include "Platform.h"

class Platform;
class Ball : public MovableObject
{
public:
	Ball();
	Ball(Vector2 position, float size);

	virtual void CheckCollisionWithScreenBorders() override;

	bool isLaunched;
	bool _isAlive;

private:
	const char* _ballSprite = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\ball\\ball_1.png";
};
