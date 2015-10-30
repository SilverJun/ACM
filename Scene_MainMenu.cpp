#include "stdafx.h"
#include "Scene_MainMenu.h"
#include "Director.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"


CScene_MainMenu::CScene_MainMenu() : CScene(sMainMenu)
{
	MenuBox[Start]	= { 100, 650, 0, 50 };
	MenuBox[Rule]	= { 0, 650, 0, 50 };
	MenuBox[Score] = { 0, 650, 0, 50 };
	MenuBox[Credit] = { 0, 650, 0, 50 };
	MenuBox[Exit]	= { 0, 650, 0, 50 };

	strcpy(MenuString[Start], "게임시작");
	strcpy(MenuString[Rule],	 "게임규칙");
	strcpy(MenuString[Score], "점수");
	strcpy(MenuString[Credit], "제작자, Alpha version 0.1");
	strcpy(MenuString[Exit], "게임종료");

	MenuBox[Start].w = (strlen(MenuString[Start]) - 1) * 25;
	MenuBox[Rule].w = (strlen(MenuString[Rule]) - 1) * 25;
	MenuBox[Score].w = (strlen(MenuString[Score]) - 1) * 25;
	MenuBox[Credit].w = (strlen(MenuString[Credit]) - 1) * 25;
	MenuBox[Exit].w = (strlen(MenuString[Exit]) - 1) * 25;

	MenuBox[Rule].x = MenuBox[Start].w + MenuBox[Start].x + 30;
	MenuBox[Score].x = MenuBox[Rule].w + MenuBox[Rule].x + 30;
	MenuBox[Credit].x = MenuBox[Score].w + MenuBox[Score].x + 30;
	MenuBox[Exit].x = MenuBox[Credit].w + MenuBox[Credit].x + 30;

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
	if (g_SoundManager->pSound[eMainMenuSound] == nullptr)
	{
		g_SoundManager->MakeSound(eMainMenuSound);
		g_SoundManager->PlaySound(eBGMChannel, eMainMenuSound);
	}
	
}


void CScene_MainMenu::Update()
{
	if (g_EventManager->g_Event.button.button == SDL_BUTTON_LEFT)
	{
		if (g_EventManager->CheckCollition_by_mouse(MenuBox[Start]))
		{
			g_SoundManager->DestroySound(eMainMenuSound);
			g_SceneManager->SetScene(sMusicSelect);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Rule]))
		{
			g_SceneManager->SetScene(sRule);
		} 
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Score]))
		{
			g_SceneManager->SetScene(sScore);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Credit]))
		{
			g_SceneManager->SetScene(sCredit);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Exit]))
		{
			g_Director->GameDone = true;
		}
	}
}

void CScene_MainMenu::Release()
{
	//g_SoundManager->DestroySound(eMainMenuSound);
	g_TextManager->DestroyTextAll();
}


