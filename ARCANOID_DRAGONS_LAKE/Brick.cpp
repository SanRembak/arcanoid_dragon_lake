#include "Brick.h"

Brick::Brick()
{
	_lives = 2;
	_sprite = createSprite(_brickSprite);
}

Brick::Brick(Vector2 position, float scale) : Brick()
{
	int width{ 0 }, height{ 0 };
	getSpriteSize(_sprite, width, height);

	width *= scale; height *= scale;
	setSpriteSize(_sprite, width, height);

	_scale = scale;
	_position.x = position.x - width / 2; _position.y = position.y;
}

void Brick::Draw()
{
	drawSprite(_sprite, _position.x, _position.y);
}

void Brick::OnCollisionHit()
{
	GetHit();
}

bool Brick::IsAlive()
{
	return _lives > 0;
}

void Brick::GetHit()
{
	_lives--;

	if (_lives > 0)
	{
		destroySprite(_sprite);
		_sprite = createSprite(_brickBrokenSprite);

		int width{ 0 }, height{ 0 };
		getSpriteSize(_sprite, width, height);

		width *= _scale; height *= _scale;
		setSpriteSize(_sprite, width, height);
	}
}
