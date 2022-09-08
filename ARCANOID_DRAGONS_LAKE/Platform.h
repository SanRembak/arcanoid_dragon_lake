#pragma once
#include "Framework.h"
#include "Object.h"
#include "Ball.h"
#include "SizeBuff.h"

class Ball;
class SizeBuff;
class Platform : public Object
{
public:
	Platform(Vector2 position, float size);

	void virtual HandleKey(FRKey key);
	void HandleBuffEffects();
	void TakeBuff(SizeBuff buff);
protected:
	void virtual ClampPos();
private:
	const char* _platformSprite = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\platform\\platform_size_1.png";

	SizeBuff* _buff;
	int _level;
	int _speed;
};