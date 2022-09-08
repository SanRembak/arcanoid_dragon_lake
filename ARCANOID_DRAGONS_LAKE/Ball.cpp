#include "Ball.h"

Ball::Ball()
{
	isLaunched = false;
	_isAlive = true;
	_speed = 2.5;
	_sprite = createSprite(_ballSprite);
}

Ball::Ball(Vector2 position, float scale) : Ball()
{
	int width{ 0 }, height{ 0 };
	getSpriteSize(_sprite, width, height);

	width *= scale; height *= scale;
	setSpriteSize(_sprite, width, height);

	_scale = scale;
	_position.x = position.x - width / 2; _position.y = position.y;
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
		_velocity = Vector2Float(0, 0);
		_isAlive = false;
	}
}


