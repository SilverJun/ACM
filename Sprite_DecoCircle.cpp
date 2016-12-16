#include "stdafx.h"
#include "Sprite_DecoCircle.h"

#include "DrawManager.h"

CSprite_DecoCircle::CSprite_DecoCircle(int RotationRate = 1, int w = 10, int h = 10) : CSprite("DecoCircle", w, h, 0, 0, w, h)
{
	SetSpriteRect((WINDOW_DEFAULT_W / 2 - (SpriteRect.w / 2)), (WINDOW_DEFAULT_H / 2 - (SpriteRect.w / 2)));
	this->RotationRate = RotationRate;

	switch (RotationRate)
	{
	case 1:
		SetSpriteImage("./Resource/dc1.png");
		SpriteImage = IMG_Load("./Resource/dc1.png");
		SDL_SetSurfaceColorMod(this->SpriteImage, 204, 51, 50);
		
		break;

	case -2:
		SetSpriteImage("./Resource/dc2.png");
		SpriteImage = IMG_Load("./Resource/dc2.png");
		SDL_SetSurfaceColorMod(SpriteImage, 231, 173, 0);
		break;
	
	case 3:
		SetSpriteImage("./Resource/dc3.png");
		SpriteImage = IMG_Load("./Resource/dc3.png");
		SDL_SetSurfaceColorMod(SpriteImage, 126, 189, 163);
		break;

	default:
		break;
	}

	if (this->SpriteTexture == nullptr)
	{
		SDL_DestroyTexture(this->SpriteTexture);
	}
	
	this->SpriteTexture = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, this->SpriteImage);
}


CSprite_DecoCircle::~CSprite_DecoCircle()
{
	SDL_FreeSurface(SpriteImage);
}





void CSprite_DecoCircle::Update()
{
	rotation += RotationRate;

	if (rotation > 360)
	{
		rotation = 0;
	}
	else if (rotation < 0)
	{
		rotation = 360;
	}
}


