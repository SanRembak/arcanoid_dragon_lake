#pragma once
#include "Framework.h"

class Platform
{
public:
	Platform(int x, int y, float size);
	void SetPos(int x, int y);
	void GetPos(int& x, int& y);
	void HandleKey(FRKey key);
	void Draw();
private:
	const char* _pathSpriteLevel_0 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\platform_size_0.png";
	const char* _pathSpriteLevel_1 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\platform_size_1.png";
	const char* _pathSpriteLevel_2 = "E:\\Unity\\Projects\\Git\\arcanoid_dragon_lake\\ARCANOID_DRAGONS_LAKE\\data\\platform_size_2.png";

	Sprite* _platformSprite;
	int _size;
	int _level;
	int _speed;

	int _x;
	int _y;
};