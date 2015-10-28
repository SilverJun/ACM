#include "stdafx.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"

#include "Scene_Game.h"
#include "Sprite_Player.h"
#include "Sprite_SpawnNote.h"



#define thisNote	static_cast<CSprite_Note *>(*lNoteItor)


enum {eSpawnNote, ePlayer};

CScene_Game::CScene_Game() : CScene(sGame)
{
	
}


CScene_Game::~CScene_Game()
{
	Release();
}


void CScene_Game::Init()
{
	addSprite(new CSprite_SpawnNote());
	addSprite(new CSprite_Player());
	//SDL_ShowCursor(0);


	g_TimeManager->Update();


	OldTime = g_TimeManager->GetTime();
	CurTime = clock() - OldTime;
	//���� �ҷ�����


}


void CScene_Game::Update()
{
	for (lNoteItor = lNote.begin(); lNoteItor != lNote.end(); )		//��Ʈ�� ȭ�� ������ ������ �� ��Ʈ�� ���ִ� �ݺ���.
	{
		if (!g_EventManager->CheckCollition(*thisNote->GetSpriteRect(), SceneBGRect))
		{
			delete thisNote;
			lNoteItor = lNote.erase(lNoteItor);
		}
		else
		{
			lNoteItor++;
		}
	}

	for (int i = 0; i < vSprite.size(); i++)		//�Ϲ� ��������Ʈ ������Ʈ
	{
		vSprite[i]->Update();
	}

	for (lNoteItor = lNote.begin(); lNoteItor != lNote.end(); lNoteItor++)			//��Ʈ�� ������Ʈ
	{
		if (thisNote != nullptr)
		{
			thisNote->Update();
		}
		
	}
	
	if (!g_EventManager->CheckCollition_by_mouse(*vSprite[eSpawnNote]->GetSpriteRect()))		//�÷��̾� ��������Ʈ�� ��� ������Ʈ ��������Ʈ�� ���� �ʵ��� ����
	{
		vSprite[ePlayer]->SetSpriteX(g_EventManager->g_Event.motion.x - 14);
		vSprite[ePlayer]->SetSpriteY(g_EventManager->g_Event.motion.y - 14);
	}

	//if (g_EventManager->KeyProsess[Space] == true)
	//{
	//	lNote.push_back(new CSprite_Note(90.f, 2.f, 10, 0));
	//	lNote.push_back(new CSprite_Note(180.f, 2.f, 10, 0));
	//	lNote.push_back(new CSprite_Note(270.f, 2.f, 10, 0));
	//	lNote.push_back(new CSprite_Note(360.f, 2.f, 10, 0));
	//}

	CurTime = clock() - OldTime;

}


void CScene_Game::Render()
{
	SDL_RenderCopy(g_DrawManager->pRenderer, SceneBGTexture, NULL, &SceneBGRect);

	for (int i = 0; i != nSprite; i++)
	{
		if (vSprite[i] != nullptr)
		{
			SDL_RenderCopyEx(g_DrawManager->pRenderer, vSprite[i]->GetSpriteTexture(), NULL, vSprite[i]->GetSpriteRect(), vSprite[i]->GetSpriteRotation(), vSprite[i]->GetSpriteCenter(), *vSprite[i]->GetSpriteFlip());
		}
	}

	for (lNoteItor = lNote.begin(); lNoteItor != lNote.end(); lNoteItor++)			//��Ʈ�� ������Ʈ
	{
		if (thisNote != nullptr)
		{
			SDL_RenderCopyEx(g_DrawManager->pRenderer, thisNote->GetSpriteTexture(), NULL, thisNote->GetSpriteRect(), /*thisNote->GetSpriteRotation()*/NULL, thisNote->GetSpriteCenter(), *thisNote->GetSpriteFlip());
		}
	}
}




void CScene_Game::Release()
{
	g_TextManager->DestroyTextAll();
	/*for (int i = 0; i < vSprite.size(); i++)
	{
		delete vSprite[i];
	}*/
	
	//SDL_ShowCursor(1);
}


void CScene_Game::addNote(CSprite_Note *newNote)
{
	lNote.push_back(newNote);
}


void CScene_Game::InitListNote()
{

}