#pragma once
#include "Framework.h"
#include "Vector2.h"

class Object
{
public:

	~Object()
	{
		destroySprite(_sprite);
	}

	void virtual SetPos(Vector2Float position)
	{
		_position = position;
	}

	Vector2Float virtual GetPos()
	{
		return _position;
	}

	Vector2Float virtual GetCenterPos()
	{
		Vector2 spriteHalfSize = GetSize() / 2;

		return Vector2Float(_position.x + spriteHalfSize.x, _position.y + spriteHalfSize.y);
	}

	Vector2 virtual GetSize()
	{
		Vector2 spriteSize;
		getSpriteSize(_sprite, spriteSize.x, spriteSize.y);

		return spriteSize;
	}

	void virtual SetSize(Vector2 size)
	{
		setSpriteSize(_sprite, size.x, size.y);
	}

	void virtual SetScale(float scale)
	{
		int width, height;
		getSpriteSize(_sprite, width, height);

		_scale = scale;
		setSpriteSize(_sprite, width * scale, height * scale);
	}

	float virtual GetScale() 
	{ 
		return _scale; 
	}

	void virtual ChangePosition(Vector2Float position)
	{
		_position.x += position.x;
		_position.y += position.y;
	}

	void virtual HandleKey(FRKey key) {};
	void virtual OnCollisionHit() {};
	void virtual Draw() { drawSprite(_sprite, _position.x, _position.y); }
protected:
	Sprite* _sprite;
	Vector2Float _position;
	float _scale;
	
	void virtual ClampPos() {};
};