#include "StdAfx.h"
#include "DrawManager.h"


CDrawManager::CDrawManager(void)
{
	pWindow = SDL_CreateWindow("SJEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_DEFAULT_W, WINDOW_DEFAULT_H,/*SDL_WINDOW_FULLSCREEN*/SDL_WINDOW_SHOWN);
	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

	NormalNoteSurface = IMG_Load("./Resource/NormalNote.png");
	RandomNoteSurface = IMG_Load("./Resource/RandomNote.png");
	SpiralNoteSurface = IMG_Load("./Resource/SpiralNote.png");
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
	SDL_FreeSurface(SpiralNoteSurface);
	SDL_FreeSurface(RandomNoteSurface);
	SDL_FreeSurface(NormalNoteSurface);

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
}
