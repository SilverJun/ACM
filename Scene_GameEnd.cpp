#include "stdafx.h"

#include "TextManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "EventManager.h"

#include "Scene_GameEnd.h"


CScene_GameEnd::CScene_GameEnd() : CScene(sGameEnd)
{
	ScoreFile.open("./Data/Score.txt", ios::in);

	ScoreFile >> BestScore >> nowScore;

	ScoreFile.close();

	ScoreBox[0] = { 300, 120, 0, 60 };
	ScoreBox[1] = { 100, 200, 0, 50 };
	ScoreBox[2] = { 100, 300, 0, 50 };
	ScoreBox[3] = { 100, 400, 0, 50 };
	ScoreBox[4] = { 20, 20, 0, 50 };

}


CScene_GameEnd::~CScene_GameEnd()
{
	Release();
}


void CScene_GameEnd::Init()
{
	sprintf(strScore[0], "*Result*");
	sprintf(strScore[1], "점수 %d", nowScore);
	
	if (nowScore > BestScore)
	{
		sprintf(strScore[2], "지난 최고점수 %d", BestScore);
		sprintf(strScore[3], "최고기록 갱신!");
		BestScore = nowScore;
	}
	else
	{
		sprintf(strScore[2], "최고점수 %d", BestScore);
		sprintf(strScore[3], "분발해야겠네요~");
	}
	sprintf(strScore[4], "메인메뉴로");


	ScoreBox[0].w = (strlen(strScore[0]) - 1) * 30;
	ScoreBox[1].w = (strlen(strScore[1]) - 1) * 25;
	ScoreBox[2].w = (strlen(strScore[2]) - 1) * 25;
	ScoreBox[3].w = (strlen(strScore[3]) - 1) * 25;
	ScoreBox[4].w = (strlen(strScore[4]) - 1) * 10;

	for (int i = 0; i < 5; i++)
	{
		g_TextManager->CreateText(strScore[i], &ScoreBox[i]);
	}

	g_SoundManager->DestroySound(eEffectMusic);
	g_SoundManager->MakeSound(eEffectMusic, eEffect_GameEnd);
	g_SoundManager->PlaySound(eChannel2, eEffectMusic);
}


void CScene_GameEnd::Update()
{
	if (g_EventManager->g_Event.button.button == SDL_BUTTON_LEFT)
	{
		if (g_EventManager->CheckCollition_by_mouse(ScoreBox[4]))
		{
			g_SceneManager->SetScene(sMainMenu);
		}
	}
}


void CScene_GameEnd::Release()
{
	ScoreFile.open("./Data/Score.txt", ios::out);
	ScoreFile << BestScore;
	ScoreFile.close();
	g_TextManager->DestroyTextAll();
}

