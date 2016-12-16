#include "StdAfx.h"
#include "DrawManager.h"


CDrawManager::CDrawManager(void)
{

	//pWindow = SDL_CreateWindow("SJEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_DEFAULT_W, WINDOW_DEFAULT_H, /*SDL_WINDOW_FULLSCREEN*/SDL_WINDOW_SHOWN);

#if _DEBUG
	pWindow = SDL_CreateWindow("SJEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_DEFAULT_W, WINDOW_DEFAULT_H, SDL_WINDOW_SHOWN);
#endif // _DEBUG

#if NDEBUG
	pWindow = SDL_CreateWindow("SJEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_DEFAULT_W, WINDOW_DEFAULT_H, SDL_WINDOW_FULLSCREEN);
#endif // _DEBUG
	
	SDL_SetWindowIcon(pWindow, IMG_Load("./Resource/icon.png"));

	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

	NormalNoteSurface = IMG_Load("./Resource/NormalNote.png");
	RandomNoteSurface = IMG_Load("./Resource/RandomNote.png");
	SpiralNoteSurface = IMG_Load("./Resource/SpiralNote.png");

	Note[0] = IMG_Load("./Resource/Note__1.png");
	Note[1] = IMG_Load("./Resource/Note__2.png");
	Note[2] = IMG_Load("./Resource/Note__3.png");
	Note[3] = IMG_Load("./Resource/Note__4.png");
	Note[4] = IMG_Load("./Resource/Note__5.png");
	Note[5] = IMG_Load("./Resource/Note__6.png");
	Note[6] = IMG_Load("./Resource/Note__7.png");
	Note[7] = IMG_Load("./Resource/Note__8.png");
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
	for (int i = 0; i < 8; i++)
	{
		SDL_FreeSurface(Note[i]);
	}

	SDL_FreeSurface(SpiralNoteSurface);
	SDL_FreeSurface(RandomNoteSurface);
	SDL_FreeSurface(NormalNoteSurface);

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
}
