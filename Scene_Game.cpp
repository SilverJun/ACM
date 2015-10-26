#include "stdafx.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"

#include "Scene_Game.h"
#include "Sprite_Player.h"
#include "Sprite_SpawnNote.h"



#define thisNote static_cast<CSprite_Note *>(*lNoteItor)

enum {eSpawnNote, ePlayer};

CScene_Game::CScene_Game() : CScene(2)
{
	
}


CScene_Game::~CScene_Game()
{
	Release();
	g_TimeManager->Init(2);
}


void CScene_Game::Init()
{
	addSprite(new CSprite_SpawnNote());
	addSprite(new CSprite_Player());
	SDL_ShowCursor(0);
}


void CScene_Game::Update()
{
	for (lNoteItor = lNote.begin(); lNoteItor != lNote.end(); lNoteItor++)		//��Ʈ�� ȭ�� ������ ������ �� ��Ʈ�� ���ִ� �ݺ���.
	{
		if (!g_EventManager->CheckCollition(*thisNote->GetSpriteRect(), SceneBGRect))
		{
			delete thisNote;
			lNote.erase(lNoteItor);
		}
	}

	for (int i = 0; i < vSprite.size(); i++)		//�Ϲ� ��������Ʈ ������Ʈ
	{
		vSprite[i]->Update();
	}

	for (lNoteItor = lNote.begin(); lNoteItor != lNote.end(); lNoteItor++)			//��Ʈ�� ������Ʈ
	{
		thisNote->Update();
	}
	
	if (!g_EventManager->CheckCollition_by_mouse(*vSprite[eSpawnNote]->GetSpriteRect()))		//�÷��̾� ��������Ʈ�� ��� ������Ʈ ��������Ʈ�� ���� �ʵ��� ����
	{
		vSprite[ePlayer]->SetSpriteX(g_EventManager->g_Event.motion.x - 14);
		vSprite[ePlayer]->SetSpriteY(g_EventManager->g_Event.motion.y - 14);
	}
}


void CScene_Game::Release()
{
	g_TextManager->DestroyTextAll();
	/*for (int i = 0; i < vSprite.size(); i++)
	{
		delete vSprite[i];
	}*/
	SDL_ShowCursor(1);
}


void CScene_Game::addNote(CSprite_Note *newNote)
{
	lNote.push_back(newNote);
}
