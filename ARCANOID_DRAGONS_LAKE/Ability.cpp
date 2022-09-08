#include "Ability.h"
#include "Game.h"

Ability::Ability()
{
	isUsed = false;
	_speed = 2;

	float xVelocity = Game::RandomRange(-5, 5) / (float)5;
	float yVelocity = Game::RandomRange(-5, 5) / (float)5;

	_velocity = Vector2Float(xVelocity, yVelocity);
}

Ability::Ability(SizeBuff buff, const char* sprite, Vector2 pos, float scale) : Ability()
{
	_sprite = createSprite(sprite);
	Vector2 size;
	getSpriteSize(_sprite, size.x, size.y);

	SetScale(scale);

	_position = Vector2Float(pos.x + size.x / 2, pos.y + size.y / 2);
	_buff = buff;
}

void Ability::HandleCollisionWithPlatform(Platform* platform)
{
	if (CheckCollisionWithObject(platform))
	{
		GiveBuff(platform);
		isUsed = true;
	}
}