#pragma once
#include "Framework.h"
#include "Object.h"
#include "Ball.h"

class Platform : public Object
{
public:
	Platform(Vector2 position, float size);

	void virtual HandleKey(FRKey key);
	void virtual Draw();
	void virtual SetPos(Vector2Float position);

	Ball* _ball;
protected:
	void virtual ClampPos();
	void virtual ChangePosition(Vector2Float position) override;
private:
	const char* _pathSpriteLevel_0 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\platform\\platform_size_0.png";
	const char* _pathSpriteLevel_1 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\platform\\platform_size_1.png";
	const char* _pathSpriteLevel_2 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\platform\\platform_size_2.png";

	int _level;
	int _speed;
};