#include "Ball.h"

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

	HandleScreenBorders();
}

void Ball::HandleScreenBorders()
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
