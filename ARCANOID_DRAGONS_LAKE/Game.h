#pragma once
#include "Framework.h"
#include "Platform.h"

class Game : public Framework {

public:

	virtual const char* GetTitle() override;
	virtual void PreInit(int& width, int& height, bool& fullscreen);

	virtual bool Init();
	virtual void Close();
	virtual bool Tick();

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
	virtual void onKeyPressed(FRKey k);
	virtual void onKeyReleased(FRKey k);

private:
	Platform* _platform;
};