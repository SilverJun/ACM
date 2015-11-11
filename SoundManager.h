#pragma once
#include "Singleton.h"

using namespace FMOD;

class CSoundManager : public Singleton<CSoundManager>
{
public:
	CSoundManager(void);
	~CSoundManager(void);

	void Init();
	void Update();
	void Release();

	void MakeSound(eSound n, eSong song);
	void DestroySound(eSound n);

	void PlaySound(eChannel c, eSound n);
	void PauseSound(eChannel c, bool b);
	void StopSound(eChannel c);

	unordered_map<eSound, Sound*> SongMap;

	unordered_map<eSong, char *> FilePath;

	System *pSystem;
	Channel *pChannel[3];
};

#define g_SoundManager CSoundManager::GetInstance()

