#include "stdafx.h"
#include "DrawManager.h"
#include "Sprite.h"

CSprite::CSprite()
{
}


CSprite::CSprite(char *nName, int w, int h, int mx, int my, int mw, int mh)
{
	SpriteName = nName;
	//SpriteRect = sRect;
	SpriteRect.w = w;
	SpriteRect.h = h;
	SpriteRect.x = 100;
	SpriteRect.y = 100;

	//SpriteMask = {mx, my, mw, mh};

	SpriteMask.x = mx;
	SpriteMask.y = my;
	SpriteMask.w = mw;
	SpriteMask.h = mh;

	rotation = 0;
	flip = SDL_FLIP_NONE;
	center.x = SpriteRect.x / 2, center.y = SpriteRect.y / 2;

	SpriteDir = cUNKNOWN;
}


CSprite::~CSprite()
{
	SDL_DestroyTexture(SpriteTexture);
}


void CSprite::SetSpriteImage(char * filepath)
{
	SpriteImage = IMG_Load(filepath);

	SpriteTexture = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, SpriteImage);

	SDL_FreeSurface(SpriteImage);
}


void CSprite::SetSpriteRect(int nX, int nY)
{
	this->SpriteRect.x = nX;
	this->SpriteRect.y = nY;
}


void CSprite::SetSpriteX(int nX)
{
	this->SpriteRect.x = nX;
}


void CSprite::SetSpriteY(int nY)
{
	this->SpriteRect.y = nY;
}


void CSprite::SetSpriteRotation(float nRot)
{
	this->rotation = nRot;
}


void CSprite::SetSpriteRotate(int nRot)
{
	this->rotation += nRot;
}


void CSprite::SetSpriteCenter(int x, int y)
{
	this->center.x = x / 2, this->center.y = y / 2;
}


SDL_Rect* CSprite::GetSpriteRect()
{
	return &SpriteRect;
}


SDL_Rect* CSprite::GetSpriteMask()
{
	return &SpriteMask;

}


int CSprite::GetSpriteX()
{
	return SpriteRect.x;
}


int CSprite::GetSpriteY()
{
	return SpriteRect.y;
}


float CSprite::GetSpriteRotation()
{
	return rotation;
}


SDL_Texture * CSprite::GetSpriteTexture()
{
	return SpriteTexture;
}


char * CSprite::GetSpriteName()
{
	return SpriteName;
}


SDL_Point * CSprite::GetSpriteCenter()
{
	return &center;
}


SDL_RendererFlip * CSprite::GetSpriteFlip()
{
	return &flip;
}

SpriteDirection CSprite::GetSpriteDirection()
{
	return SpriteDir;
}




