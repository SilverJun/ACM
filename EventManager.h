#pragma once
#include "Singleton.h"
#include "Sprite.h"
class CEventManager : public Singleton<CEventManager>
{
public:
	CEventManager();
	~CEventManager();

	void Init();
	void Update();
	void Release();

	SDL_Event g_Event;
	bool bMBtnDown;

	bool KeyProsess[9];
	const Uint8 *keystate;
	

	int nKey;

	void InitKeyProsess();


	bool CheckCollition(SDL_Rect mask1, SDL_Rect mask2);
	bool CheckCollition_by_mouse(SDL_Rect mask);
	bool CheckCollition_by_Circle(CSprite *Circle1, CSprite *Circle2);

};

#define g_EventManager CEventManager::GetInstance()
#define g_EventKey CEventManager::g_Event.key.keysym.sym