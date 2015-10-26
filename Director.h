#pragma once
#include "Singleton.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "TextManager.h"

class CDirector : public Singleton<CDirector>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void GameLoop();
	
public:

	bool GameDone;

};

#define g_Director CDirector::GetInstance()

