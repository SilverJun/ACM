#include "StdAfx.h"
#include "SceneManager.h"
#include "TimeManager.h"

#include "Scene_MainMenu.h"
#include "Scene_MusicSelect.h"
#include "Scene_Game.h"
#include "Scene_Rule.h"
#include "Scene_Score.h"
#include "Scene_Credit.h"
#include "Scene_GameEnd.h"


CSceneManager::CSceneManager(void)
{
	thisScene = nullptr;
}


CSceneManager::~CSceneManager(void)
{
}


void CSceneManager::SetScene(int idx)
{
	if (thisScene != nullptr)
		delete thisScene;

	switch (idx)
	{
	case 0:
		//thisScene = new CScene;
		//SceneIdx = 0;
		break;

	case sMainMenu:
		thisScene = new CScene_MainMenu;
		SceneIdx = sMainMenu;
		break;

	case sMusicSelect:
		thisScene = new CScene_MusicSelect;
		SceneIdx = sMusicSelect;
		break;

	case sGame_Song1:
		thisScene = new CScene_Game(eGameMusic1);
		SceneIdx = sGame_Song1;
		break;

	case sGame_Song2:
		thisScene = new CScene_Game(eGameMusic2);
		SceneIdx = sGame_Song2;
		break;

	case sRule:
		thisScene = new CScene_Rule;
		SceneIdx = sRule;
		break;

	case sScore:
		thisScene = new CScene_Score;
		SceneIdx = sScore;
		break;

	case sCredit:
		thisScene = new CScene_Credit;
		SceneIdx = sCredit;
		break;

	case sGameEnd:
		thisScene = new CScene_GameEnd;
		SceneIdx = sCredit;
		break;

	default:
		break;
	}

	thisScene->Init();
}


void CSceneManager::Init()
{
	SceneIdx = 1;
	SetScene(1);
}

void CSceneManager::Update()
{
	thisScene->Update();
	g_TimeManager->Update();
}

void CSceneManager::Render()
{
	thisScene->Render();
}

void CSceneManager::Release()
{
	if (thisScene != nullptr)
		delete thisScene;
}
