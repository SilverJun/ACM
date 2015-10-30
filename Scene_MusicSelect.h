#pragma once
#include "Scene.h"

enum eMusicBox{ PlayList, music1, music2 };

class CScene_MusicSelect : public CScene
{
public:
	CScene_MusicSelect();
	~CScene_MusicSelect();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	SDL_Rect MenuBox[3];
	char MenuString[3][100];
};

