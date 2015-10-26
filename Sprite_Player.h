#pragma once
#include "Sprite.h"
class CSprite_Player : public CSprite

{
public:
	CSprite_Player();
	~CSprite_Player();

	virtual void Update() override;
};

