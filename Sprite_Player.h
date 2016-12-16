#pragma once
#include "Sprite.h"
class CSprite_Player : public CSprite

{
public:
	CSprite_Player();
	~CSprite_Player();

	virtual void Update() override;
	virtual void Render() override;

private:
	SDL_Rect afterImg[4];
	Uint8 alpha[4];
	SDL_Surface *afterImgsf[4];
	clock_t afterTime[4];

};

