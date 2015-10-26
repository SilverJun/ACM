#include "StdAfx.h"
#include "SceneManager.h"
#include "TimeManager.h"

#include "Scene_MainMenu.h"
#include "Scene_Game.h"
#include "Scene_Rule.h"
#include "Scene_Score.h"
#include "Scene_Credit.h"


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
		std::cout << "메뉴신 동적할당" << std::endl;
		thisScene = new CScene_MainMenu;
		SceneIdx = sMainMenu;
		break;

	case sGame:
		thisScene = new CScene_Game;
		SceneIdx = sGame;
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
	g_TimeManager->Update(SceneIdx);
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
