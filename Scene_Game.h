#pragma once
#include "Scene.h"

#include "Sprite_Note.h"

class CScene_Game : public CScene
{
public:
	CScene_Game();
	~CScene_Game();

	void addNote(CSprite_Note *);
	
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	list<CSprite_Note *> lNote;
	list<CSprite_Note *>::iterator lNoteItor;
	
};

