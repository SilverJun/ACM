#pragma once
#include "Singleton.h"

using namespace FMOD;

#define MAX_SOUND	5

class CSoundManager : public Singleton<CSoundManager>
{
public:
	CSoundManager(void);
	~CSoundManager(void);

	void Init();
	void Update();
	void Release();

	void MakeSound(eSound n);
	void DestroySound(eSound n);

	void PlaySound(eChannel c, eSound n);
	void PauseSound(eChannel c, bool b);
	void StopSound(eChannel c);
	
	char *path[5];

	System *pSystem;
	Channel *pChannel[3];
	Sound * pSound[MAX_SOUND];
};

#define g_SoundManager CSoundManager::GetInstance()

