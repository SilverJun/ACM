#include "stdafx.h"
#include "SceneManager.h"


#include "EventManager.h"


CEventManager::CEventManager()
{
	nKey = 9;
	InitKeyProsess();
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
			g_SceneManager->SetScene(1);
			break;
		case SDLK_F11:
			g_SceneManager->SetScene(2);
			break;

		case SDLK_ESCAPE:
			exit(0);
			break;

		//case SDLK_1:
		//	KeyProsess[n1] = true;
		//	break;
		//
		//case SDLK_2:
		//	KeyProsess[n2] = true;
		//	break;
		//
		//case SDLK_3:
		//	KeyProsess[n3] = true;
		//	break;
		//
		//case SDLK_4:
		//	KeyProsess[n4] = true;
		//	break;
		//
		//default:
		//	break;
		}
		//if (g_EventKey == SDLK_UP)
		//{
		//	KeyProsess[Up] = true;
		//}
		//if (g_EventKey == SDLK_DOWN)
		//{
		//	KeyProsess[Down] = true;
		//}
		//if (g_EventKey == SDLK_LEFT)
		//{
		//	KeyProsess[Left] = true;
		//}
		//if (g_EventKey == SDLK_RIGHT)
		//{
		//	KeyProsess[Right] = true;
		//}
		//if (g_EventKey == SDLK_SPACE)
		//{
		//	KeyProsess[Space] = true;
		//}

		//if (keystate[SDL_SCANCODE_LEFT])
		//{
		//	KeyProsess[Left] = true;
		//}
		//if (keystate[SDL_SCANCODE_RIGHT])
		//{
		//	KeyProsess[Right] = true;
		//}
		//if (keystate[SDL_SCANCODE_UP])
		//{
		//	KeyProsess[Up] = true;
		//}
		//if (keystate[SDL_SCANCODE_DOWN])
		//{
		//	KeyProsess[Down] = true;
		//}
	}
	else if (g_Event.type == SDL_QUIT)
	{
		exit(0);
	}
	else
	{
		InitKeyProsess();
	}
	SDL_FlushEvents(1073741881, 1073742106);
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


bool CEventManager::CheckCollition_by_Circle(CSprite *Circle, SDL_Rect mask)
{
	float r = Circle->GetSpriteRect()->w / 2;
	SDL_Point CircleCenter = { Circle->GetSpriteRect()->x + r, Circle->GetSpriteRect()->y + r };

	
	SDL_Point Pos[4] = {
		{ mask.x, mask.y },
		{ mask.x + mask.w, mask.y },
		{ mask.x, mask.y + mask.h },
		{ mask.x + mask.w, mask.y + mask.h } 
	};

	float d;
	
	int i;
	if (CheckCollition(*Circle->GetSpriteRect(),mask))
	{
		//상황1		-
		for (i = 0; i + Pos[0].x < Pos[1].x; i++)
		{
			d = sqrtf(((CircleCenter.x - (Pos[0].x + i))*(CircleCenter.x - (Pos[0].x + i))) + ((CircleCenter.y - Pos[0].y)*(CircleCenter.y - Pos[0].y)));
			if (d - r <= 0)
			{
				return true;
			}
		}

		//상황2		| I
		for (i = 0; i + Pos[1].y < Pos[3].y; i++)
		{
			d = sqrtf(((CircleCenter.x - Pos[1].x)*(CircleCenter.x - Pos[1].x)) + ((CircleCenter.y - (Pos[1].y + i))*(CircleCenter.y - (Pos[1].y + i))));
			if (d - r <= 0)
			{
				return true;
			}
		}
		//상황3		_
		for (i = 0; i + Pos[3].x < Pos[4].x; i++)
		{
			d = sqrtf(((CircleCenter.x - (Pos[3].x + i))*(CircleCenter.x - (Pos[3].x + i))) + ((CircleCenter.y - Pos[3].y)*(CircleCenter.y - Pos[3].y)));
			if (d - r <= 0)
			{
				return true;
			}
		}
		//상황4		I |
		for (i = 0; i + Pos[0].y < Pos[3].y; i++)
		{
			d = sqrtf(((CircleCenter.x - Pos[0].x)*(CircleCenter.x - Pos[0].x)) + ((CircleCenter.y - (Pos[0].y + i))*(CircleCenter.y - (Pos[0].y + i))));
			if (d - r <= 0)
			{
				return true;
			}
		}
	}
	return false;
}
	
