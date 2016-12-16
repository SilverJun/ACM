#pragma once
#include "Sprite.h"
class CSprite_DecoCircle :
	public CSprite
{
public:
	CSprite_DecoCircle(int RotationRate, int w, int h);
	~CSprite_DecoCircle();

	virtual void Update() override;

private:
	int RotationRate;

};

