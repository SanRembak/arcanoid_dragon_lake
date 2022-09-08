#pragma once
#include "Object.h"

class MovableObject: public Object
{
public:
	virtual void Fly();

	void SetVelocity(Vector2Float velocity) { _velocity = velocity; }
	Vector2Float GetVelocity() { return _velocity; }

	void SetSpeed(float speed) { _speed = speed; }
	float GetSpeed() { return _speed; }

	virtual void CheckCollisionWithScreenBorders();
	void HandleCollisionWithObject(Object* object);
	bool CheckCollisionWithObject(Object* object);

protected:
	void ReflectVelocityRelativeToObject(Object* object);

	Vector2Float _velocity;
	float _speed;
};