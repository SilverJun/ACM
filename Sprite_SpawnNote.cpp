#include "stdafx.h"
#include "Sprite_SpawnNote.h"

#include "DrawManager.h"

CSprite_SpawnNote::CSprite_SpawnNote() : CSprite("SpawnNote", 100,100,0,0,100,100)
{
	SetSpriteImage("./Resource/SpawnNote.png");
	SetSpriteRect((WINDOW_DEFAULT_W / 2 - (SpriteRect.w / 2)), (WINDOW_DEFAULT_H / 2 - (SpriteRect.w / 2)));
	SpriteImage = IMG_Load("./Resource/SpawnNote.png");
}


CSprite_SpawnNote::~CSprite_SpawnNote()
{
	SDL_FreeSurface(SpriteImage);
}


void CSprite_SpawnNote::Update()
{
	
}


void CSprite_SpawnNote::Render()
{
	SDL_RenderCopyEx(g_DrawManager->pRenderer, this->GetSpriteTexture(), NULL, this->GetSpriteRect(), this->GetSpriteRotation(), this->GetSpriteCenter(), *this->GetSpriteFlip());
}


void CSprite_SpawnNote::RandColor()
{
	Uint8 r = rand() % (255 - 30) + 30, g = rand() % (255 - 30) + 30, b = rand() % (255 - 30) + 30;

	SDL_SetSurfaceColorMod(SpriteImage, r, g, b);

	if (SpriteTexture != nullptr)
	{
		SDL_DestroyTexture(SpriteTexture);
	}

	SpriteTexture = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, SpriteImage);
}
