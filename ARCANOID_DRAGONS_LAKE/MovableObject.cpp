#include "MovableObject.h"

void MovableObject::Fly()
{
	_position += _velocity * _speed;

	CheckCollisionWithScreenBorders();
}

void MovableObject::CheckCollisionWithScreenBorders()
{
	Vector2 screenSize, ballSize;
	getScreenSize(screenSize.x, screenSize.y);
	ballSize = GetSize();

	if (_position.x < 0)
	{
		_velocity.x *= -1;
		_position.x = 0;
	}

	else if (_position.x + ballSize.x > screenSize.x)
	{
		_velocity.x *= -1;
		_position.x = screenSize.x - ballSize.x;
	}

	else if (_position.y < 0)
	{
		_velocity.y *= -1;
		_position.y = 0;
	}

	else if (_position.y + ballSize.y > screenSize.x)
	{
		_velocity.y *= -1;
		_position.y = screenSize.x - ballSize.y;
	}
}

void MovableObject::HandleCollisionWithObject(Object* object)
{
	if (CheckCollisionWithObject(object))
	{
		ReflectVelocityRelativeToObject(object);
		object->OnCollisionHit();
	}
}

bool MovableObject::CheckCollisionWithObject(Object* object)
{
	Vector2 objectSize = object->GetSize();
	Vector2 ballSize = GetSize();

	Vector2Float objectCenterPosition = object->GetCenterPos();
	Vector2Float ballCenterPosition = GetCenterPos();

	Vector2Float directionFromObject = ballCenterPosition - objectCenterPosition;
	Vector2Float objectToBallNormal = directionFromObject.normal();
	Vector2Float ballNormal = objectToBallNormal * -1;

	Vector2Float nearPointFromBall = ballCenterPosition +
		Vector2Float(ballSize.x / 2 * ballNormal.x,
			ballSize.y / 2 * ballNormal.y);

	Vector2Float nearPointFromObject = objectCenterPosition +
		Vector2Float(objectSize.x / 2 * objectToBallNormal.x,
			objectSize.y / 2 * objectToBallNormal.y);

	float distanceFromCenterToBall = GetDistance(objectCenterPosition, nearPointFromBall);
	float distanceFromCenterToBorderObject = GetDistance(objectCenterPosition, nearPointFromObject);

	return distanceFromCenterToBall <= distanceFromCenterToBorderObject;
}

void MovableObject::ReflectVelocityRelativeToObject(Object* object)
{
	Vector2Float topLeftPlatformNormalPos = (object->GetPos() - object->GetCenterPos()).normal();

	Vector2Float objectCenterPosition = object->GetCenterPos();
	Vector2Float ballCenterPosition = GetCenterPos();

	Vector2Float directionFromObject = ballCenterPosition - objectCenterPosition;
	Vector2Float objectToBallNormal = directionFromObject.normal();

	float minX = topLeftPlatformNormalPos.x;
	float maxX = topLeftPlatformNormalPos.x * -1;

	float minY = topLeftPlatformNormalPos.y;
	float maxY = topLeftPlatformNormalPos.y * -1;

	if (objectToBallNormal.x > minX && objectToBallNormal.x < maxX)
	{
		_velocity.y *= -1;

		if (objectToBallNormal.y < 0)
			_position.y -= 1;
		else
			_position.y += 1;
	}

	if (objectToBallNormal.y > minY && objectToBallNormal.y < maxY)
	{
		_velocity.x *= -1;

		if (objectToBallNormal.x < 0)
			_position.x -= 1;
		else
			_position.x += 1;
	}
}