#pragma once
#include "Singleton.h"

//using namespace FMOD;

class CSoundManager : public Singleton<CSoundManager>
{
public:
	CSoundManager(void);
	~CSoundManager(void);

	void Init();
	void Update();
	void Release();

	//System *pSystem;
	//Channel *pChannel[3];
	//vector<Sound *> vSound;
};

#define g_SoundManager CSoundManager::GetInstance()

