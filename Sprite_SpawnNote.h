#pragma once
#include "Sprite.h"
class CSprite_SpawnNote : public CSprite
{
public:
	CSprite_SpawnNote();
	~CSprite_SpawnNote();

	virtual void Update() override;
	virtual void Render();

	void RandColor();
};

