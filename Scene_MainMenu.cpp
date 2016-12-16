#include "stdafx.h"
#include "Scene_MainMenu.h"
#include "Director.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"


CScene_MainMenu::CScene_MainMenu() : CScene(sMainMenu)
{
	SetSceneBGImage("./Resource/ACM.png");
	MenuImg = IMG_Load("./Resource/Menu.png");
	MenuTxt = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, MenuImg);

	MenuBox[Start]	= { 100, 600, 0, 50 };
	MenuBox[Rule]	= { 320, 600, 0, 50 };
	MenuBox[Score] = { 560, 600, 0, 50 };
	MenuBox[Credit] = { 750, 600, 0, 50 };
	MenuBox[Exit]	= { 920, 600, 0, 50 };

	strcpy(MenuString[Start], "게임시작");
	strcpy(MenuString[Rule],	 "게임규칙");
	strcpy(MenuString[Score], "점  수");
	strcpy(MenuString[Credit], "제작자");
	strcpy(MenuString[Exit], "게임종료");

	MenuBox[Start].w = (strlen(MenuString[Start]) - 1) * 25;
	MenuBox[Rule].w = (strlen(MenuString[Rule]) - 1) * 25;
	MenuBox[Score].w = (strlen(MenuString[Score]) - 1) * 25;
	MenuBox[Credit].w = (strlen(MenuString[Credit]) - 1) * 25;
	MenuBox[Exit].w = (strlen(MenuString[Exit]) - 1) * 25;

	
}


CScene_MainMenu::~CScene_MainMenu()
{
	Release();
}


void CScene_MainMenu::Init()
{
	for (int i = 0; i < 5; i++)
	{
		g_TextManager->CreateText(MenuString[i], &MenuBox[i]);
	}

	bool b;
	g_SoundManager->pChannel[eBGMChannel]->isPlaying(&b);

	if (!b)
	{
		g_SoundManager->MakeSound(eMainMenuSound, eMainMenu);
		g_SoundManager->PlaySound(eBGMChannel, eMainMenuSound);
	}
	
	if (g_SoundManager->SongMap.find(eEffectMusic) != g_SoundManager->SongMap.end())
	{
		g_SoundManager->DestroySound(eEffectMusic);
	}
	g_SoundManager->MakeSound(eEffectMusic, eEffect_Click);
}


void CScene_MainMenu::Update()
{
	if (g_EventManager->bMBtnDown)
	{
		g_EventManager->bMBtnDown = false;
		if (g_EventManager->CheckCollition_by_mouse(MenuBox[Start]))
		{
			g_SoundManager->PlaySound(eChannel2, eEffectMusic);
			g_SoundManager->pChannel[eBGMChannel]->stop();
			g_SoundManager->DestroySound(eMainMenuSound);
			g_SceneManager->SetScene(sMusicSelect);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Rule]))
		{
			g_SoundManager->PlaySound(eChannel2, eEffectMusic);
			g_SceneManager->SetScene(sRule);
		} 
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Score]))
		{
			g_SoundManager->PlaySound(eChannel2, eEffectMusic);
			g_SceneManager->SetScene(sScore);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Credit]))
		{
			g_SoundManager->PlaySound(eChannel2, eEffectMusic);
			g_SceneManager->SetScene(sCredit);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Exit]))
		{
			g_SoundManager->PlaySound(eChannel2, eEffectMusic);
			g_Director->GameDone = true;
		}
	}
}

void CScene_MainMenu::Render()
{
	SDL_RenderCopy(g_DrawManager->pRenderer, SceneBGTexture, NULL, &SceneBGRect);

	for (int i = 0; i < 5; i++)
	{
		SDL_RenderCopy(g_DrawManager->pRenderer, MenuTxt, NULL, &MenuBox[i]);
	}
}

void CScene_MainMenu::Release()
{
	//g_SoundManager->DestroySound(eMainMenuSound);
	SDL_FreeSurface(MenuImg);
	SDL_DestroyTexture(MenuTxt);

	g_TextManager->DestroyTextAll();
}


