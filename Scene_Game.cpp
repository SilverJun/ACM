#include "stdafx.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"
#include "SoundManager.h"

#include "Scene_Game.h"
#include "Sprite_Player.h"
#include "Sprite_SpawnNote.h"

enum {eSpawnNote, ePlayer};


CScene_Game::CScene_Game() : CScene(sThisScene)
{
}


CScene_Game::CScene_Game(eSound Song) : CScene(sThisScene)
{
	ThisSong = Song;
	switch (ThisSong)
	{
	case eGameMusic1:
		SinkFile.open("./Resource/Duelle_amp_CiRRO-Your_Addiction_Culture_Code_Remix.txt");
		break;
	case eGameMusic2:
		SinkFile.open("./Resource/English_Listening_Type_B.txt");
		break;
	default:
		break;
	}
	

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
	SDL_ShowCursor(0);

	g_SoundManager->MakeSound(ThisSong);

	unsigned int time;
	g_SoundManager->pSound[ThisSong]->getLength(&time, FMOD_TIMEUNIT_MS);
	GameEndTime = time;

	SinkFile >> SinkTime >> NoteType >> CommonSink.Rotation >> CommonSink.Speed;

	g_TimeManager->Update();
	
	g_SoundManager->PlaySound(eChannel1, ThisSong);

	//interval = 10;
	CommonSink.Rotation = 0;
	CommonSink.Rotation_Rate = 15;
	CommonSink.Speed = 10;
	CommonSink.Speed_Rate = 0;

	NormalSink = CommonSink;
	FourWaySink = CommonSink;
	SprialSink = CommonSink;
	RandomSink = CommonSink;

	SprialWay = note_Spiral_Left;
	
	bIsSprial = false;
	bIsRandomNote = false;
	bIsGameEnd = false;

	Score = 0;
	ScoreBox = { 20, 20, 0, 50 };
	sprintf(strScore, "점수 %d", Score);
	ScoreBox.w = (strlen(strScore) - 1) * 25;

	g_TextManager->CreateText(strScore, &ScoreBox);
}


void CScene_Game::Update()
{
	//GameEndTime;

	//CurTime = g_TimeManager->GetTime() - OldTime;
	unsigned int time;
	g_SoundManager->pChannel[eChannel1]->getPosition(&time, FMOD_TIMEUNIT_MS);
	CurTime = time;

	for (int i = 0; i < vNote.size(); )		//노트처리 반복문
	{
		vNote[i]->Update();
		if (!g_EventManager->CheckCollition(*vNote[i]->GetSpriteRect(), SceneBGRect))		//스크린 밖으로 나가면 동적해제
		{
			delete vNote[i];
			swap(vNote[i], vNote.back());
			vNote.pop_back();
			Score += 100;
			sprintf(strScore, "점수 %d", Score);
			ScoreBox.w = (strlen(strScore) - 1) * 25;
			g_TextManager->ModifyText(strScore, 0);
		}
		else if (g_EventManager->CheckCollition_by_Circle(vSprite[ePlayer],vNote[i]))		//플레이어와 맞으면 동적해제
		{
			delete vNote[i];
			swap(vNote[i], vNote.back());
			vNote.pop_back();
			Score -= 500;
			sprintf(strScore, "점수 %d", Score);
			ScoreBox.w = (strlen(strScore) - 1) * 25;
			g_TextManager->ModifyText(strScore, 0);
		}
		else
		{
			i++;
		}
	}
	

	vSprite[eSpawnNote]->Update();
	vSprite[ePlayer]->Update();
	
	if (!g_EventManager->CheckCollition_by_mouse(*vSprite[eSpawnNote]->GetSpriteRect()))		//플레이어 스프라이트가 가운데 스폰노트 스프라이트를 뚫지 않도록 셋팅
	{
		vSprite[ePlayer]->SetSpriteX(g_EventManager->g_Event.motion.x - 14);
		vSprite[ePlayer]->SetSpriteY(g_EventManager->g_Event.motion.y - 14);
	}

	if (CurTime > SinkTime)		//노트가 나와야 하는 타이밍
	{
		switch (NoteType)
		{
		case note_Normal:
			bIsRandomNote = false;

			NormalSink.Rotation = GetMouseRotation();
			NormalSink.Speed = CommonSink.Speed;

			vNote.push_back(new CSprite_Note(NormalSink.Rotation, 0.f, NormalSink.Speed, 0.f));
			bIsSprial = false;
			bIsRandomNote = true;
			break;

		case note_FourWayNormal:
			bIsRandomNote = false;
			FourWaySink.Rotation = CommonSink.Rotation;
			FourWaySink.Speed = CommonSink.Speed;

			vNote.push_back(new CSprite_Note(FourWaySink.Rotation, 0.f, FourWaySink.Speed, 0.f));
			vNote.push_back(new CSprite_Note(FourWaySink.Rotation + 90, 0.f, FourWaySink.Speed, 0.f));
			vNote.push_back(new CSprite_Note(FourWaySink.Rotation + 180, 0.f, FourWaySink.Speed, 0.f));
			vNote.push_back(new CSprite_Note(FourWaySink.Rotation + 270, 0.f, FourWaySink.Speed, 0.f));

			FourWaySink.Rotation += 45;

			bIsSprial = false;
			bIsRandomNote = true;
			break;

		case note_Spiral_Left:
			SprialSink.Rotation = CommonSink.Rotation;
			SprialSink.Speed = CommonSink.Speed;
			SprialWay = note_Spiral_Left;
			bIsSprial = true;
			break;
		case note_Spiral_Right:
			SprialSink.Rotation = CommonSink.Rotation;
			SprialSink.Speed = CommonSink.Speed;
			SprialWay = note_Spiral_Right;
			bIsSprial = true;
			break;

		default:
			break;
		}

		SinkFile >> SinkTime >> NoteType >> CommonSink.Rotation >> CommonSink.Speed;
	}

	if (bIsSprial)		//달팽이노트
	{
		if (CurTime - IntervalTime > 10)
		{
			switch (SprialWay)
			{
			case note_Spiral_Left:
				vNote.push_back(new CSprite_Note(SprialSink.Rotation, 0.f, SprialSink.Speed, 0.f));
				SprialSink.Rotation -= CommonSink.Rotation_Rate;
				SprialSink.Speed += CommonSink.Speed_Rate;
				break;

			case note_Spiral_Right:
				vNote.push_back(new CSprite_Note(SprialSink.Rotation, 0.f, SprialSink.Speed, 0.f));
				SprialSink.Rotation += CommonSink.Rotation_Rate;
				SprialSink.Speed += CommonSink.Speed_Rate;
				break;

			default:
				break;
			}
			
			IntervalTime = CurTime;
		}
		bIsRandomNote = false;
	}

	if (bIsRandomNote)
	{
		if (CurTime - IntervalTime > 5)
		{
			RandomSink.Rotation = rand() % 360;
			RandomSink.Speed = 7;
			vNote.push_back(new CSprite_Note(RandomSink.Rotation, 0.f, RandomSink.Speed, 0.f));
		}
	}

	if (CurTime >= GameEndTime)
	{
		bIsGameEnd = true;
	}

	if (vNote.size() == 0 && bIsGameEnd)
	{
		ScoreFile.open("./Data/Score.txt",ios::app);
		ScoreFile << " " << Score;
		g_SceneManager->SetScene(sGameEnd);
	}
}


void CScene_Game::Render()
{
	SDL_Rect temprt;
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;

	SDL_SetRenderDrawColor(g_DrawManager->pRenderer, 255, 0, 0, 255);
	SDL_RenderCopy(g_DrawManager->pRenderer, SceneBGTexture, NULL, &SceneBGRect);

	for (int i = 0; i < vNote.size(); i++)			//노트들 업데이트
	{
		if (vNote[i] != nullptr)
		{
			SDL_RenderCopyEx(g_DrawManager->pRenderer, vNote[i]->GetSpriteTexture(), NULL, vNote[i]->GetSpriteRect(), vNote[i]->GetSpriteRotation(), vNote[i]->GetSpriteCenter(), *vNote[i]->GetSpriteFlip());
#ifdef _DEBUG
			temprt = *vNote[i]->GetSpriteRect();

			x1 = temprt.x, x2 = temprt.w + temprt.x, x3 = temprt.x, x4 = temprt.w + temprt.x;
			y1 = temprt.y, y2 = temprt.y, y3 = temprt.h + temprt.y, y4 = temprt.h + temprt.y;
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x1, y1, x2, y2);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x1, y1, x3, y3);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x2, y2, x4, y4);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x3, y3, x4, y4);
#endif
		}
	}

	for (int i = 0; i != nSprite; i++)
	{
		if (vSprite[i] != nullptr)
		{
			SDL_RenderCopyEx(g_DrawManager->pRenderer, vSprite[i]->GetSpriteTexture(), NULL, vSprite[i]->GetSpriteRect(), vSprite[i]->GetSpriteRotation(), vSprite[i]->GetSpriteCenter(), *vSprite[i]->GetSpriteFlip());
#ifdef _DEBUG
			temprt = *vSprite[ePlayer]->GetSpriteMask();

			x1 = temprt.x, x2 = temprt.w + temprt.x, x3 = temprt.x, x4 = temprt.w + temprt.x;
			y1 = temprt.y, y2 = temprt.y, y3 = temprt.h + temprt.y, y4 = temprt.h + temprt.y;
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x1, y1, x2, y2);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x1, y1, x3, y3);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x2, y2, x4, y4);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x3, y3, x4, y4);
#endif
		}
	}
}


void CScene_Game::Release()
{
	g_SoundManager->StopSound(eChannel1);
	g_SoundManager->DestroySound(ThisSong);
	g_TextManager->DestroyTextAll();
	ScoreFile.close();
	SinkFile.close();

	/*for (int i = 0; i < vSprite.size(); i++)
	{
		delete vSprite[i];
	}*/
	
	SDL_ShowCursor(1);
}


void CScene_Game::addNote(CSprite_Note *newNote)
{
	vNote.push_back(newNote);
}


float CScene_Game::GetMouseRotation()
{
	float offset_x = g_EventManager->g_Event.motion.x - (WINDOW_DEFAULT_W / 2 - 20);
	float offset_y = g_EventManager->g_Event.motion.y - (WINDOW_DEFAULT_H / 2 - 20);
	float radian = atan2(offset_y, offset_x);
	
	//Shark.x += cos(radian) * 5.0f;	// * -sinf(radian) * 5.0f;
	//Shark.y += -sin(radian) * 5.0f;	// * cosf(radian) * 5.0f;

	return (180.0f * radian) / M_PI;
}