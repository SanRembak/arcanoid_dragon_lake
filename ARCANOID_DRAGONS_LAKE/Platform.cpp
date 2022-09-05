#include "Platform.h"

Platform::Platform(int x, int y, float size)
{
	_x = x; _y = y;
	_level = 1;
	_speed = 15;
	_platformSprite = createSprite(_pathSpriteLevel_1);

	int width{ 0 }, height{ 0 };
	getSpriteSize(_platformSprite, width, height);

	width *= size; height *= size;
	setSpriteSize(_platformSprite, width, height);
}

void Platform::SetPos(int x, int y)
{
	_x = x;
	_y = y;
}

void Platform::GetPos(int& x, int& y)
{
	x = _x;
	y = _y;
}

void Platform::HandleKey(FRKey key)
{
	switch (key)
	{
	case FRKey::RIGHT:
		_x += _speed;
		break;

	case FRKey::LEFT:
		_x -= _speed;
		break;

	default:
		std::cout << "ERROR: Unknown FRKey" << std::endl;
		break;
	}
}

void Platform::Draw()
{
	drawSprite(_platformSprite, _x, _y);
}
