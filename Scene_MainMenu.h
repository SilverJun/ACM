#pragma once
#include "Scene.h"

enum eMenuBox{Start, Rule, Score, Credit, Exit};

class CScene_MainMenu : public CScene
{
public:
	CScene_MainMenu();
	~CScene_MainMenu();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	SDL_Rect MenuBox[5];
	char MenuString[5][100];

	SDL_Surface *MenuImg;
	SDL_Texture *MenuTxt;
};

