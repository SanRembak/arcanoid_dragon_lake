#include "Ball.h"
#include "Platform.h"

Ball::Ball(Vector2 position, float size)
{
	_level = 1;
	_speed = 2;
	_sprite = createSprite(_pathSpriteLevel_1);

	int width{ 0 }, height{ 0 };
	getSpriteSize(_sprite, width, height);

	width *= size; height *= size;
	setSpriteSize(_sprite, width, height);

	_position.x = position.x - width / 2; _position.y = position.y;
}

void Ball::Draw()
{
	drawSprite(_sprite, _position.x, _position.y);
}

void Ball::Fly()
{
	_position += _velocity * _speed;

	CheckCollisionWithScreenBorders();
}

void Ball::CheckCollisionWithScreenBorders()
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

void Ball::HandleCollisionWithObject(Object* object)
{
	if (CheckCollisionWithObject(object))
	{
		ReflectVelocityRelativeToObject(object);
		object->OnCollisionHit();
	}
}

bool Ball::CheckCollisionWithObject(Object* object)
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

void Ball::ReflectVelocityRelativeToObject(Object* object)
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


