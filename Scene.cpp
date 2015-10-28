#include "StdAfx.h"
#include "Scene.h"
#include "TimeManager.h"

CScene::CScene(eScene n)
{
	SceneBGRect.x = 0;
	SceneBGRect.y = 0;
	SceneBGRect.w = WINDOW_DEFAULT_W;
	SceneBGRect.h = WINDOW_DEFAULT_H;
	SetSceneBGImage("./bg2.png");
	nSprite = 0;
	sThisScene = n;
}


CScene::~CScene(void)
{
	for (int i = 0; i < vSprite.size(); i++)
	{
		delete vSprite[i];
	}
	SDL_DestroyTexture(SceneBGTexture);
}


void CScene::SetSceneBGImage(char *filepath)
{
	SceneBGImage = IMG_Load(filepath);

	SceneBGTexture = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, SceneBGImage);

	SDL_FreeSurface(SceneBGImage);
}


CSprite* CScene::FindSpriteByName(char * _name)
{
	for (int i = 0; i != nSprite; i++)
	{
		if (vSprite[i]->GetSpriteName() == _name)
		{
			return vSprite[i];
		}
	}
}


eScene CScene::GetThisScene()
{
	return sThisScene;
}


void CScene::addSprite(CSprite *newSprite)
{
	vSprite.push_back(newSprite);
	nSprite++;
}


void CScene::Init()
{

}

void CScene::Update()
{
	
}

void CScene::Render()
{
	SDL_RenderCopy(g_DrawManager->pRenderer, SceneBGTexture, NULL, &SceneBGRect);

	for (int i = 0; i != nSprite; i++)
	{
		if (vSprite[i] != nullptr)
		{
			SDL_RenderCopyEx(g_DrawManager->pRenderer, vSprite[i]->GetSpriteTexture(), NULL, vSprite[i]->GetSpriteRect(), vSprite[i]->GetSpriteRotation(), vSprite[i]->GetSpriteCenter(), *vSprite[i]->GetSpriteFlip());
		}
	}
}

void CScene::Release()
{

}

