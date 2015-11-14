#pragma once
#include "Sprite.h"
class CSprite_Bar : public CSprite
{
public:
	CSprite_Bar();
	~CSprite_Bar();

	virtual void Update() override;

private:
	clock_t NowTime;

	clock_t EndTime;

	int NowX;

	SDL_Rect DrawBox;
};

