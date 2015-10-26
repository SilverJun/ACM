#pragma once
#include "DrawManager.h"
#include "Sprite.h"

class CScene
{
protected:
	//==== 스프라이트 ====
	vector<CSprite *> vSprite;
	int nSprite;
	//===================

	//==== Scene의 배경 ====
	SDL_Surface *SceneBGImage;
	SDL_Texture *SceneBGTexture;
	SDL_Rect SceneBGRect;
	//======================

public:
	CScene(int n);
	virtual ~CScene(void);

	void SetSceneBGImage(char *);
	CSprite* FindSpriteByName(char *);

	void addSprite(CSprite *);

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};

