#include "stdafx.h"

#include "SceneManager.h"
#include "SoundManager.h"
#include "EventManager.h"
#include "TextManager.h"

#include "Scene_Rule.h"


CScene_Rule::CScene_Rule() : CScene(sRule)
{
	RuleBox[0] = { 465, 220, 0, 60 };
	RuleBox[1] = { 500, 400, 0, 40 };
	RuleBox[2] = { 490, 450, 0, 40 };
	RuleBox[3] = { 540, 500, 0, 40 };
	RuleBox[4] = { 410, 550, 0, 40 };
	RuleBox[5] = { 100, 100, 0, 50 };
}


CScene_Rule::~CScene_Rule()
{
	Release();
}


void CScene_Rule::Init()
{
	sprintf(strRule[0], "*How To Play*");
	sprintf(strRule[1], "노래에 맞게 탄막이 나옵니다.");
	sprintf(strRule[2], "탄막을 피하며 점수를 쌓으세요.");
	sprintf(strRule[3], "마우스로 플레이합니다.");
	sprintf(strRule[4], "탄막을 맞지 않은 시간에 비례해 점수를 얻습니다.");
	sprintf(strRule[5], "메인메뉴로");


	RuleBox[0].w = (strlen(strRule[0]) - 1) * 30;
	RuleBox[1].w = (strlen(strRule[1]) - 1) * 10;
	RuleBox[2].w = (strlen(strRule[2]) - 1) * 10;
	RuleBox[3].w = (strlen(strRule[3]) - 1) * 10;
	RuleBox[4].w = (strlen(strRule[4]) - 1) * 10;
	RuleBox[5].w = (strlen(strRule[5]) - 1) * 10;

	for (int i = 0; i < 6; i++)
	{
		g_TextManager->CreateText(strRule[i], &RuleBox[i]);
	}
}


void CScene_Rule::Update()
{
	if (g_EventManager->bMBtnDown)
	{
		g_EventManager->bMBtnDown = false;
		if (g_EventManager->CheckCollition_by_mouse(RuleBox[5]))
		{
			g_SceneManager->SetScene(sMainMenu);
		}
	}
}


void CScene_Rule::Release()
{
	g_TextManager->DestroyTextAll();
}
