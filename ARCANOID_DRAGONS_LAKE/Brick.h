#pragma once
#include "Framework.h"
#include "Object.h"

class Brick : public Object
{
public:
	Brick();
	Brick(Vector2 position, float size);

	virtual void Draw() override;
	virtual void OnCollisionHit() override;
	bool IsAlive();
private:
	const char* _brickSprite = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\bricks\\brick_1.png";
	const char* _brickBrokenSprite = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\bricks\\brick_broken_1.png";

	void GetHit();

	int _lives;
};