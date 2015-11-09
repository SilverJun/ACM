#include "stdafx.h"

#include "SceneManager.h"
#include "TextManager.h"
#include "EventManager.h"

#include "Scene_Score.h"


CScene_Score::CScene_Score() : CScene(sScore)
{
	ScoreFile.open("./Data/Score.txt", ios::in);

	ScoreFile >> BestScore;

	ScoreFile.close();

	ScoreBox[0] = { 300, 120, 0, 60 };
	ScoreBox[1] = { 100, 200, 0, 40 };
	ScoreBox[2] = { 100, 300, 0, 50 };
	ScoreBox[3] = { 20, 20, 0, 50 };
}


CScene_Score::~CScene_Score()
{
	Release();
}

void CScene_Score::Init()
{
	sprintf(strScore[0], "*점수*");
	sprintf(strScore[1], "※현재 YourAddction만 점수기록 지원합니다.");
	sprintf(strScore[2], "최고점수 %d", BestScore);
	sprintf(strScore[3], "메인메뉴로");


	ScoreBox[0].w = (strlen(strScore[0]) - 1) * 30;
	ScoreBox[1].w = (strlen(strScore[1]) - 1) * 20;
	ScoreBox[2].w = (strlen(strScore[2]) - 1) * 25;
	ScoreBox[3].w = (strlen(strScore[3]) - 1) * 10;

	for (int i = 0; i < 4; i++)
	{
		g_TextManager->CreateText(strScore[i], &ScoreBox[i]);
	}
}


void CScene_Score::Update()
{
	if (g_EventManager->g_Event.button.button == SDL_BUTTON_LEFT)
	{
		if (g_EventManager->CheckCollition_by_mouse(ScoreBox[3]))
		{
			g_SceneManager->SetScene(sMainMenu);
		}
	}
}


void CScene_Score::Release()
{
	g_TextManager->DestroyTextAll();
}


