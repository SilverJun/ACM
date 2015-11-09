#pragma once
#include "Scene.h"
class CScene_Rule : public CScene
{
public:
	CScene_Rule();
	~CScene_Rule();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	char strRule[6][50];
	SDL_Rect RuleBox[6];
	fstream ScoreFile;
};

