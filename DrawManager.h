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
	
};

#define g_DrawManager CDrawManager::GetInstance()


