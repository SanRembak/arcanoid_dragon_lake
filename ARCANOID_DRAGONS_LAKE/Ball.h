#pragma once
#include "Framework.h"
#include "Object.h"
#include "Platform.h"

class Platform;
class Ball : public Object
{
public:
	Ball();
	Ball(Vector2 position, float size);
	virtual void Draw() override;

	void Fly();

	void SetVelocity(Vector2Float velocity) { _velocity = velocity; }
	Vector2Float GetVelocity() { return _velocity; }

	void SetSpeed(float speed) { _speed = speed; }
	float GetSpeed() { return _speed; }

	void CheckCollisionWithScreenBorders();
	void HandleCollisionWithObject(Object* object);
	bool CheckCollisionWithObject(Object* object);

	bool isLaunched;
	bool _isAlive;

private:
	const char* _ballSprite = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\ball\\ball_1.png";

	void ReflectVelocityRelativeToObject(Object* object);

	Vector2Float _velocity;

	int _level;
	float _speed;
};
