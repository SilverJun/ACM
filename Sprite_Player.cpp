#include "stdafx.h"

#include "EventManager.h"
#include "DrawManager.h"
#include "TimeManager.h"

#include "Sprite_Player.h"


CSprite_Player::CSprite_Player() : CSprite("Player", 29, 29, 5, 5, 19, 19)
{
	SetSpriteImage("./Resource/Player.png");
	
	alpha[0] = 191;
	alpha[1] = 153;
	alpha[3] = 114;
	alpha[2] = 76;

	for (int i = 0; i < 4; i++)
	{
		
		afterImgsf[i] = IMG_Load("./Resource/Player.png");
		SDL_SetSurfaceAlphaMod(afterImgsf[i], alpha[i]);
		afterTime[i] = clock();
	}
	
	
}


CSprite_Player::~CSprite_Player()
{

}


void CSprite_Player::Update()
{

	afterImg[0] = SpriteRect;

	SpriteMask.x = SpriteRect.x + 5;
	SpriteMask.y = SpriteRect.y + 5;

	if (g_TimeManager->GetTime() - afterTime[0] > 40)
	{
		afterTime[0] = clock();
		afterImg[0] = SpriteRect;
	}
	if (g_TimeManager->GetTime() - afterTime[1] > 60)
	{
		afterTime[1] = clock();
		afterImg[1] = afterImg[0];
	}
	if (g_TimeManager->GetTime() - afterTime[2] > 80)
	{
		afterTime[2] = clock();
		afterImg[2] = afterImg[1];
	}
	if (g_TimeManager->GetTime() - afterTime[3] > 100)
	{
		afterTime[3] = clock();
		afterImg[3] = afterImg[2];
	}
}


void CSprite_Player::Render()
{
	
	for (int i = 0; i < 4; i++)
	{
		SDL_Texture *aftertx = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, afterImgsf[i]);
		SDL_RenderCopyEx(g_DrawManager->pRenderer, aftertx, NULL, &afterImg[i], this->GetSpriteRotation(), this->GetSpriteCenter(), *this->GetSpriteFlip());
		SDL_DestroyTexture(aftertx);
	}

	SDL_RenderCopyEx(g_DrawManager->pRenderer, this->GetSpriteTexture(), NULL, this->GetSpriteRect(), this->GetSpriteRotation(), this->GetSpriteCenter(), *this->GetSpriteFlip());

}


