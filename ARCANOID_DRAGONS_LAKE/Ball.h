#pragma once
#include "Framework.h"
#include "Object.h"

class Ball : public Object
{
public:
	Ball(Vector2 position, float size);
	virtual void Draw() override;
	
	void Fly();

	void SetVelocity(Vector2Float velocity) {_velocity = velocity;}
	Vector2Float GetVelocity() { return _velocity; }

	void SetSpeed(float speed) { _speed = speed; }
	float GetSpeed() { return _speed; }
	void HandleScreenBorders();
private:
	const char* _pathSpriteLevel_0 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\ball\\ball_0.png";
	const char* _pathSpriteLevel_1 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\ball\\ball_1.png";
	const char* _pathSpriteLevel_2 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\ball\\ball_2.png";
	const char* _pathSpriteLevel_3 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\ball\\ball_3.png";

	Vector2Float _velocity;

	int _level;
	float _speed;
};