#include "stdafx.h"
#include "Scene_MusicSelect.h"
#include "SceneManager.h"
#include "EventManager.h"
#include "TextManager.h"

CScene_MusicSelect::CScene_MusicSelect() : CScene(sMusicSelect)
{
	MenuBox[PlayList] = { 100, 100, 0, 50 };
	MenuBox[music1] = { 100, 200, 0, 50 };
	MenuBox[music2] = { 100, 300, 0, 50 };
	MenuBox[music3] = { 100, 400, 0, 50 };

	strcpy(MenuString[PlayList], "PlayList");
	strcpy(MenuString[music1], "Your_Addiction_Culture_Code_Remix");
	strcpy(MenuString[music2], "영어 듣기 B형 리믹스(미완성)");
	strcpy(MenuString[music3], "KDrew - Circles (Original Mix)");

	MenuBox[PlayList].w = (strlen(MenuString[PlayList]) - 1) * 25;
	MenuBox[music1].w = (strlen(MenuString[music1]) - 1) * 25;
	MenuBox[music2].w = (strlen(MenuString[music2]) - 1) * 25;
	MenuBox[music3].w = (strlen(MenuString[music3]) - 1) * 25;
}


CScene_MusicSelect::~CScene_MusicSelect()
{
	Release();
}


void CScene_MusicSelect::Init()
{
	for (int i = 0; i < 4; i++)
	{
		g_TextManager->CreateText(MenuString[i], &MenuBox[i]);
	}
}


void CScene_MusicSelect::Update()
{
	if (g_EventManager->g_Event.button.button == SDL_BUTTON_LEFT)
	{
		if (g_EventManager->CheckCollition_by_mouse(MenuBox[music1]))
		{
			g_SceneManager->SetParam(eYour_Addiction);
			g_SceneManager->SetScene(sGame);
		}
		//else if (g_EventManager->CheckCollition_by_mouse(MenuBox[music2]))
		//{
		//	g_SceneManager->SetParam(eEnglish_Listening);
		//	g_SceneManager->SetScene(sGame);
		//}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[music3]))
		{
			g_SceneManager->SetParam(eCircles);
			g_SceneManager->SetScene(sGame);
		}
	}
}


void CScene_MusicSelect::Release()
{
	g_TextManager->DestroyTextAll();
}

