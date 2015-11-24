#include "stdafx.h"

#include "DrawManager.h"
#include "SoundManager.h"

#include "Sprite_Bar.h"


CSprite_Bar::CSprite_Bar() : CSprite("Bar", 400, 30, 0, 0, 400, 30)
{
	SetSpriteImage("Bar.png");
	SetSpriteRect(400, 30);

}


CSprite_Bar::~CSprite_Bar()
{
}

void CSprite_Bar::Update()
{
	unsigned int time;
	g_SoundManager->pChannel[eChannel1]->getPosition(&time, FMOD_TIMEUNIT_MS);
	NowTime = time;

	g_SoundManager->SongMap[eGameTheme]->getLength(&time, FMOD_TIMEUNIT_MS);
	EndTime = time;
	
	NowX = (NowTime * 400 / EndTime);

	
	SDL_SetRenderDrawColor(g_DrawManager->pRenderer, 0, 0, 0, 255);
	DrawBox = {400, 30, NowX, 30};
	SDL_RenderFillRect(g_DrawManager->pRenderer, &DrawBox);
}


