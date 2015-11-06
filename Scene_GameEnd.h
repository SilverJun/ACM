#pragma once
#include "Scene.h"


class CScene_GameEnd : public CScene
{
public:
	CScene_GameEnd();
	~CScene_GameEnd();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	int nowScore, BestScore;

	char strScore[5][50];
	SDL_Rect ScoreBox[5];

	fstream ScoreFile;
};

