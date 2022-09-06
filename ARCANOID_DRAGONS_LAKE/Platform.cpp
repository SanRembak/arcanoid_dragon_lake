#include "Platform.h"

Platform::Platform(Vector2 position, float size)
{
	_level = 1;
	_speed = 30;
	_sprite = createSprite(_pathSpriteLevel_1);

	int width{ 0 }, height{ 0 };
	getSpriteSize(_sprite, width, height);

	width *= size; height *= size;
	setSpriteSize(_sprite, width, height);

	_position.x = position.x - width / 2; _position.y = position.y;
}

void Platform::HandleKey(FRKey key)
{
	Vector2Float direction = Vector2Float(0, 0);
	switch (key)
	{
	case FRKey::RIGHT:
		direction += Vector2Float(_speed, 0);
		break;

	case FRKey::LEFT:
		direction -= Vector2Float(_speed, 0);
		break;
	}

	ClampPos();
	ChangePosition(direction);
}

void Platform::Draw()
{
	drawSprite(_sprite, _position.x, _position.y);
}

void Platform::ClampPos()
{
	int screenWidth, screenHeight;
	int spriteWidth, spriteHeight;

	getScreenSize(screenWidth, screenHeight);
	getSpriteSize(_sprite, spriteWidth, spriteHeight);

	Vector2Float newPosition = _position;

	if (newPosition.x < 0)
	{
		newPosition.x = 0;
	}

	else if (newPosition.x + spriteWidth > screenWidth)
	{
		newPosition.x = screenWidth - spriteWidth;
	}

	SetPos(newPosition);
}

void Platform::ChangePosition(Vector2Float position)
{
	Vector2Float relativeDiffOfBall;

	if (_ball != NULL)
	{
		relativeDiffOfBall = _ball->GetPos() - _position;
	}

	Object::ChangePosition(position);

	if (_ball != NULL)
	{
		_ball->SetPos(_position + relativeDiffOfBall);
	}
}

void Platform::SetPos(Vector2Float position)
{
	Vector2Float relativeDiffOfBall;

	if (_ball != NULL)
	{
		relativeDiffOfBall = _ball->GetPos() - _position;
	}

	_position = position;

	if (_ball != NULL)
	{
		_ball->SetPos(_position + relativeDiffOfBall);
	}
}
