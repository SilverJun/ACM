#pragma once

#include "Singleton.h"
#include "unzip.h"

class CResourceManager : public Singleton<CResourceManager>
{
private:
	SDL_RWops *rw;
	HZIP hz;
	ZIPENTRY ze;
	int index;
	void *mem;

	char *key;

	vector<SDL_Surface *>vRememberSurface;

public:
	CResourceManager();
	~CResourceManager();

	void Init();
	void Release();

	SDL_RWops *LoadItem(char *name);
	int addRememberSurface(SDL_Surface *s);
	SDL_Surface *GetRememberSurface(int idx);


	SDL_Surface *NormalNoteSurface;
	SDL_Surface *RandomNoteSurface;
	SDL_Surface *SpiralNoteSurface;

	SDL_Surface *Note[8];
};

#define g_ResourceManager CResourceManager::GetInstance()