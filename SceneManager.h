#pragma once
#include "Singleton.h"
#include "Scene.h"

class CSceneManager : public Singleton<CSceneManager>
{
protected:
	CScene *thisScene;
	int SceneIdx;

public:
	CSceneManager(void);
	~CSceneManager(void);

	void SetScene(int idx = 0);

	void Init();
	void Update();
	void Render();
	void Release();

};

#define g_SceneManager CSceneManager::GetInstance()