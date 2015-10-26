#pragma once
#include "Scene.h"
class CScene_MusicSelect : public CScene
{
public:
	CScene_MusicSelect();
	~CScene_MusicSelect();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
};

