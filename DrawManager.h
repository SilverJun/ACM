#pragma once

#include "Singleton.h"

class CDrawManager : public Singleton<CDrawManager>
{
public:
	CDrawManager(void);
	~CDrawManager(void);

	void Init();
	void Update();
	void Render();
	void Release();

	SDL_Window *pWindow;
	SDL_Renderer *pRenderer;
	
	SDL_Surface *NormalNoteSurface;
	SDL_Surface *RandomNoteSurface;
	SDL_Surface *SpiralNoteSurface;

	SDL_Surface *Note[8];
};

#define g_DrawManager CDrawManager::GetInstance()


