#pragma once
#include "MovableObject.h"
#include "Platform.h"
#include "SizeBuff.h"

class Platform;
class SizeBuff;
class Ability : public MovableObject
{
public:
	Ability();
	Ability(SizeBuff buff, const char* sprite, Vector2 pos, float scale);
	void HandleCollisionWithPlatform(Platform* platform);
	virtual void GiveBuff(Platform* platform) { platform->TakeBuff(); };
	bool isUsed;
protected:
	SizeBuff _buff;
};