#include "StdAfx.h"
#include "DrawManager.h"

CDrawManager::CDrawManager(void)
{
	pWindow = SDL_CreateWindow("SJEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_DEFAULT_W, WINDOW_DEFAULT_H,/*SDL_WINDOW_FULLSCREEN*/SDL_WINDOW_SHOWN);
	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
}


CDrawManager::~CDrawManager(void)
{

}


void CDrawManager::Init()
{
	SDL_RenderClear(pRenderer);
}

void CDrawManager::Update()
{
}

void CDrawManager::Render()
{
	SDL_RenderPresent(pRenderer);
}

void CDrawManager::Release()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
}
