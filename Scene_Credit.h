#pragma once

#include "Scene.h"

class CScene_Credit : public CScene
{
public:
	CScene_Credit();
	~CScene_Credit();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	SDL_Rect CreditBox[6];
	char CreditString[6][100];

	//SDL_Rect 
};

