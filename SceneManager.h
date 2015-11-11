#pragma once
#include "Singleton.h"
#include "Scene.h"

class CSceneManager : public Singleton<CSceneManager>
{
protected:
	CScene *thisScene;
	int SceneIdx;

public:
	int Param;
	CSceneManager(void);
	~CSceneManager(void);

	void SetScene(int idx = 0);

	void Init();
	void Update();
	void Render();
	void Release();

	void SetParam(int n);
};

#define g_SceneManager CSceneManager::GetInstance()