#include "stdafx.h"
#include "Scene_Credit.h"

#include "TextManager.h"
#include "EventManager.h"
#include "SceneManager.h"


CScene_Credit::CScene_Credit() : CScene(sCredit)
{
	CreditBox[0] = { 100, 200, 0, 40 };
	CreditBox[1] = { 100, 270, 0, 40 };
	CreditBox[2] = { 100, 320, 0, 40 };
	CreditBox[3] = { 100, 370, 0, 40 };
	CreditBox[4] = { 100, 420, 0, 40 };
	CreditBox[5] = { 100, 100, 0, 50 };

	strcpy(CreditString[0], "ACM 제작진 Team.수은마법진");
	strcpy(CreditString[1], "기획 : 차혁진");
	strcpy(CreditString[2], "프로그래밍 : 장은준");
	strcpy(CreditString[3], "그래픽 : 박수연");
	strcpy(CreditString[4], "플레이 해주셔서 감사합니다!");
	strcpy(CreditString[5], "메인메뉴로");

	CreditBox[0].w = (strlen(CreditString[0]) - 1) * 15;
	CreditBox[1].w = (strlen(CreditString[1]) - 1) * 15;
	CreditBox[2].w = (strlen(CreditString[2]) - 1) * 15;
	CreditBox[3].w = (strlen(CreditString[3]) - 1) * 15;
	CreditBox[4].w = (strlen(CreditString[4]) - 1) * 15;
	CreditBox[5].w = (strlen(CreditString[5]) - 1) * 10;
}


CScene_Credit::~CScene_Credit()
{
	Release();
}


void CScene_Credit::Init()
{
	for (int i = 0; i < 6; i++)
	{
		g_TextManager->CreateText(CreditString[i], &CreditBox[i]);
	}
}


void CScene_Credit::Update()
{
	if (g_EventManager->bMBtnDown)
	{
		g_EventManager->bMBtnDown = false;
		if (g_EventManager->CheckCollition_by_mouse(CreditBox[5]))
		{
			g_SceneManager->SetScene(sMainMenu);
		}
	}
}


void CScene_Credit::Release()
{
	g_TextManager->DestroyTextAll();
}

