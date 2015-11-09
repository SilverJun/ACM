#pragma once
#include "Scene.h"
class CScene_Score : public CScene
{
public:
	CScene_Score();
	~CScene_Score();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	int BestScore;

	char strScore[4][50];
	SDL_Rect ScoreBox[4];

	fstream ScoreFile;
};

