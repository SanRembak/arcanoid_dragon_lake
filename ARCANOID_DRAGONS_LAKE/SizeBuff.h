#pragma once
#include "Platform.h"
#include "Timer.h"

class Platform;
class Timer;
class SizeBuff
{
public:
	SizeBuff()
	{
		sizeValue = 0;
		duration = Timer(0);
		originalXSize = 0;
	}

	SizeBuff(float sizeValue)
	{
		this->sizeValue = sizeValue;
		duration = Timer(20);
		originalXSize = 0;
	}

	SizeBuff(float sizeValue, Timer timer)
	{
		this->sizeValue = sizeValue;
		duration = timer;
		originalXSize = 0;
	}

	float sizeValue;
	float originalXSize;
	Timer duration;

	void UseBuff(Platform* platform)
	{
		Vector2 size;
		//NOTE: C2070 use of undefined type 'Platform' and the same error with others comented lines here
		//size = platform->GetSize();

		if (!duration.IsStarted())
		{
			duration.Start();
			originalXSize = size.x;
		}

		float currentSizeValue = 1 + sizeValue;

		if (currentSizeValue > 2)
			currentSizeValue = 2;

		else if (currentSizeValue < 0.5)
			currentSizeValue = 0.5;

		//platform->SetSize(Vector2(originalXSize * currentSizeValue, size.y));
	}

	void Reset(Platform* platform)
	{
		//Vector2 size;
		//size = platform->GetSize();

		//platform->SetSize(Vector2(originalXSize, size.y));
	}

	SizeBuff operator+=(SizeBuff buff)
	{
		sizeValue += buff.sizeValue;
		duration.Start();

		return SizeBuff(sizeValue, duration);
	}
};