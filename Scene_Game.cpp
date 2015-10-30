#include "stdafx.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"
#include "SoundManager.h"

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
	vSprite[eSpawnNote]->Update();
	addSprite(new CSprite_Player());
	//SDL_ShowCursor(0);

	SinkFile.open("./Resource/Duelle_amp_CiRRO-Your_Addiction_Culture_Code_Remix.txt");
	g_SoundManager->MakeSound(eGameMusic1);
	
	SinkFile >> SinkTime;

	g_TimeManager->Update();

	g_SoundManager->PlaySound(eBGMChannel, eGameMusic1);

	interval = 10;
	Rotation = 0;
	Rotation_Rate = 10;
	Speed = 10;
	Speed_Rate = 0;
	
}


void CScene_Game::Update()
{
	//CurTime = g_TimeManager->GetTime() - OldTime;
	unsigned int time;
	g_SoundManager->pChannel[eBGMChannel]->getPosition(&time, FMOD_TIMEUNIT_MS);
	CurTime = time;
	for (lNoteItor = lNote.begin(); lNoteItor != lNote.end(); )		//노트가 화면 밖으로 나가면 그 노트를 없애는 반복문.
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

	//for (int i = 0; i < vSprite.size(); i++)		//일반 스프라이트 업데이트
	//{
	//	vSprite[i]->Update();
	//}
	vSprite[ePlayer]->Update();

	for (lNoteItor = lNote.begin(); lNoteItor != lNote.end(); lNoteItor++)			//노트들 업데이트
	{
		if (thisNote != nullptr)
		{
			thisNote->Update();
		}
	}
	
	if (!g_EventManager->CheckCollition_by_mouse(*vSprite[eSpawnNote]->GetSpriteRect()))		//플레이어 스프라이트가 가운데 스폰노트 스프라이트를 뚫지 않도록 셋팅
	{
		vSprite[ePlayer]->SetSpriteX(g_EventManager->g_Event.motion.x - 14);
		vSprite[ePlayer]->SetSpriteY(g_EventManager->g_Event.motion.y - 14);
	}

	cout << SinkTime << ", " << CurTime << endl;
	if (CurTime > SinkTime)
	{
		lNote.push_back(new CSprite_Note(Rotation, 0.f, Speed, 0.f));
		Rotation += Rotation_Rate;
		Speed += Speed_Rate;
		SinkFile >> SinkTime;
	}

	//if (g_EventManager->KeyProsess[Space] == true)
	//{
	//	lNote.push_back(new CSprite_Note(90.f, 2.f, 10, 0));
	//	lNote.push_back(new CSprite_Note(180.f, 2.f, 10, 0));
	//	lNote.push_back(new CSprite_Note(270.f, 2.f, 10, 0));
	//	lNote.push_back(new CSprite_Note(360.f, 2.f, 10, 0));
	//}
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

	for (lNoteItor = lNote.begin(); lNoteItor != lNote.end(); lNoteItor++)			//노트들 업데이트
	{
		if (thisNote != nullptr)
		{
			SDL_RenderCopyEx(g_DrawManager->pRenderer, thisNote->GetSpriteTexture(), NULL, thisNote->GetSpriteRect(), /*thisNote->GetSpriteRotation()*/NULL, thisNote->GetSpriteCenter(), *thisNote->GetSpriteFlip());
		}
	}
}




void CScene_Game::Release()
{
	g_SoundManager->StopSound(eBGMChannel);
	g_SoundManager->DestroySound(eGameMusic1);
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