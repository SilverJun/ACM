#pragma once
#include "Scene.h"

#define MAX_MUSIC	3

enum eMusicBox{ PlayList, music1, music2, music3, music4 };

class CScene_MusicSelect : public CScene
{
public:
	CScene_MusicSelect();
	~CScene_MusicSelect();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	SDL_Rect MenuBox[MAX_MUSIC + 1];
	char MenuString[MAX_MUSIC + 1][100];
};

