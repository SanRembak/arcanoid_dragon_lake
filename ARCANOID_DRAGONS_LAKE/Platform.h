#pragma once
#include "Framework.h"
#include "Object.h"
#include "Ball.h"

class Ball;
class Platform : public Object
{
public:
	Platform(Vector2 position, float size);

	void virtual HandleKey(FRKey key);

protected:
	void virtual ClampPos();
private:
	const char* _platformSprite = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\platform\\platform_size_1.png";

	int _level;
	int _speed;
};