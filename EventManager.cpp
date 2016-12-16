#include "stdafx.h"
#include "SceneManager.h"


#include "EventManager.h"


CEventManager::CEventManager()
{
	nKey = 9;
	InitKeyProsess();
	bMBtnDown = false;
}


CEventManager::~CEventManager()
{
}


void CEventManager::Init()
{
	SDL_Init(SDL_INIT_EVENTS);

}


void CEventManager::Update()
{
	SDL_PollEvent(&g_Event);
	keystate = SDL_GetKeyboardState(NULL);
	if (g_Event.type == SDL_KEYDOWN)
	{
		switch (g_Event.key.keysym.sym)
		{
		case SDLK_F10:
			g_SceneManager->SetScene(sMainMenu);
			break;
		case SDLK_F11:
			g_SceneManager->SetScene(sMusicSelect);
			break;

		case SDLK_ESCAPE:
			exit(0);
			break;
		}
		if (g_EventKey == SDLK_SPACE)
		{
			KeyProsess[Space] = true;
		}
	}
	else if (g_Event.type == SDL_QUIT)
	{
		exit(0);
	}
	else
	{
		InitKeyProsess();
	}


	if (g_Event.type == SDL_MOUSEBUTTONDOWN)
	{
		bMBtnDown = true;
	}
	else if (g_Event.type == SDL_MOUSEBUTTONUP)
	{
		bMBtnDown = false;
	}
	
	//SDL_FlushEvents(1073741881, 1073742106);
}


void CEventManager::Release()
{

}


void CEventManager::InitKeyProsess()
{
	for (int i = 0; i < nKey; i++)
	{
		KeyProsess[i] = false;
	}
}


bool CEventManager::CheckCollition(SDL_Rect mask1, SDL_Rect mask2)
{
	if ((mask1.x <= mask2.x || mask1.x <= mask2.x + mask2.w) && mask1.x + mask1.w >= mask2.x)
	{
		if ((mask1.y <= mask2.y || mask1.y <= mask2.y + mask2.h) && mask1.y + mask1.h >= mask2.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool CEventManager::CheckCollition_by_mouse(SDL_Rect mask)
{
	if (g_Event.motion.x >= mask.x && g_Event.motion.x <= mask.x + mask.w)
	{
		if (g_Event.motion.y >= mask.y && g_Event.motion.y <= mask.y + mask.h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

	
bool CEventManager::CheckCollition_by_Circle(CSprite *Circle1, CSprite *Circle2)
{
	SDL_Point c1, c2;

	int c1r, c2r;

	c1r = Circle1->GetSpriteMask()->w / 2;
	c2r = Circle2->GetSpriteRect()->w / 2;

	//c1 = *Circle1->GetSpriteCenter();
	//c2 = *Circle2->GetSpriteCenter();

	c1.x = Circle1->GetSpriteMask()->x + c1r;
	c1.y = Circle1->GetSpriteMask()->y + c1r;
	c2.x = Circle2->GetSpriteRect()->x + c2r;
	c2.y = Circle2->GetSpriteRect()->y + c2r;

	int x = c2.x - c1.x;
	int y = c2.y - c1.y;

	int r = c1r + c2r;

	if (((x*x) + (y*y)) < (r*r))
	{
		return true;
	}

	return false;
}