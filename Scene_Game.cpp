#include "stdafx.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"
#include "SoundManager.h"

#include "Scene_Game.h"
#include "Sprite_Player.h"
#include "Sprite_SpawnNote.h"
#include "Sprite_Bar.h"

enum {eSpawnNote, ePlayer, eBar};


CScene_Game::CScene_Game() : CScene(sThisScene)
{
	SetSong(static_cast<eSong>(g_SceneManager->Param));
}


CScene_Game::~CScene_Game()
{
	Release();
}


void CScene_Game::SetSong(eSong Song)
{
	ThisSong = Song;

	switch (ThisSong)
	{
	case eYour_Addiction:
		SinkFile.open("./Resource/Duelle_amp_CiRRO-Your_Addiction_Culture_Code_Remix.txt");
		SetSceneBGImage("./Resource/Duelle_amp_CiRRO-Your_Addiction_Culture_Code_Remix.jpg");
		break;
	case eEnglish_Listening:
		SinkFile.open("./Resource/English_Listening_Type_B.txt");
		//SetSceneBGImage("./Resource/Duelle_amp_CiRRO-Your_Addiction_Culture_Code_Remix.jpg");
		break;
	case eCircles:
		SinkFile.open("./Resource/KDrew - Circles (Original Mix).txt");
		//SetSceneBGImage("./Resource/Duelle_amp_CiRRO-Your_Addiction_Culture_Code_Remix.jpg");
		break;
	default:
		break;
	}
}


void CScene_Game::Init()
{
	addSprite(new CSprite_SpawnNote());
	vSprite[eSpawnNote]->Update();
	addSprite(new CSprite_Player());
	addSprite(new CSprite_Bar());
	SDL_ShowCursor(0);

	g_SoundManager->MakeSound(eGameTheme, ThisSong);

	unsigned int time;
	g_SoundManager->SongMap[eGameTheme]->getLength(&time, FMOD_TIMEUNIT_MS);
	GameEndTime = time;

	ScoreTime = 100;
	xScoreTime = 1000;
	xScore = 1.0f;

	SinkFile >> SinkTime >> NoteType >> CommonSink.Rotation >> CommonSink.Speed;

	g_TimeManager->Update();
	
	g_SoundManager->PlaySound(eChannel1, eGameTheme);

	//interval = 10;
	CommonSink.Rotation = 0;
	CommonSink.Rotation_Rate = 15;
	CommonSink.Speed = 10;
	CommonSink.Speed_Rate = 0;

	NormalSink = CommonSink;
	FourWaySink = CommonSink;
	SpiralSink = CommonSink;
	RandomSink = CommonSink;

	SpiralWay = note_Spiral_Left;
	
	bIsSpiral = false;
	bIsRandomNote = false;
	bIsGameEnd = false;

	Score = 0;
	ScoreBox[0] = { 20, 20, 0, 50 };
	ScoreBox[1] = { 20, 80, 0, 50 };

	sprintf(strScore[0], "점수 %d", Score);
	sprintf(strScore[1], "x%.1f", xScore);

	ScoreBox[0].w = (strlen(strScore[0]) - 1) * 25;
	ScoreBox[1].w = (strlen(strScore[1]) - 1) * 25;

	g_TextManager->SetColor(255, 255, 255);

	g_TextManager->CreateText(strScore[0], &ScoreBox[0]);
	g_TextManager->CreateText(strScore[1], &ScoreBox[1]);
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
		}
		else if (g_EventManager->CheckCollition_by_Circle(vSprite[ePlayer],vNote[i]))		//플레이어와 맞으면 동적해제
		{
			delete vNote[i];
			swap(vNote[i], vNote.back());
			vNote.pop_back();
			xScore = 0.9f;
			//xScoreTime = CurTime;
		}
		else
		{
			i++;
		}
	}
	
	if (!g_EventManager->CheckCollition_by_mouse(*vSprite[eSpawnNote]->GetSpriteRect()))		//플레이어 스프라이트가 가운데 스폰노트 스프라이트를 뚫지 않도록 셋팅
	{
		if (g_EventManager->CheckCollition_by_mouse(SceneBGRect))
		{
			vSprite[ePlayer]->SetSpriteX(g_EventManager->g_Event.motion.x - 14);
			vSprite[ePlayer]->SetSpriteY(g_EventManager->g_Event.motion.y - 14);
		}
	}

	vSprite[eSpawnNote]->Update();
	vSprite[ePlayer]->Update();

	
	if (CurTime > SinkTime)		//노트가 나와야 하는 타이밍
	{
		switch (NoteType)
		{
		case note_Normal:
			bIsRandomNote = false;

			NormalSink.Rotation = GetMouseRotation();
			NormalSink.Speed = CommonSink.Speed;

			vNote.push_back(new CSprite_Note(note_Normal, NormalSink.Rotation, 0.f, NormalSink.Speed, 0.f));
			bIsSpiral = false;
			bIsRandomNote = true;
			break;

		case note_FourWayNormal:
			bIsRandomNote = false;
			FourWaySink.Rotation = CommonSink.Rotation;
			FourWaySink.Speed = CommonSink.Speed;

			vNote.push_back(new CSprite_Note(note_FourWayNormal, FourWaySink.Rotation, 0.f, FourWaySink.Speed, 0.f));
			vNote.push_back(new CSprite_Note(note_FourWayNormal, FourWaySink.Rotation + 90, 0.f, FourWaySink.Speed, 0.f));
			vNote.push_back(new CSprite_Note(note_FourWayNormal, FourWaySink.Rotation + 180, 0.f, FourWaySink.Speed, 0.f));
			vNote.push_back(new CSprite_Note(note_FourWayNormal, FourWaySink.Rotation + 270, 0.f, FourWaySink.Speed, 0.f));

			FourWaySink.Rotation += 45;

			bIsSpiral = false;
			bIsRandomNote = true;
			break;

		case note_Spiral_Left:
			SpiralSink.Rotation = CommonSink.Rotation;
			SpiralSink.Speed = CommonSink.Speed;
			SpiralWay = note_Spiral_Left;
			bIsSpiral = true;
			break;
		case note_Spiral_Right:
			SpiralSink.Rotation = CommonSink.Rotation;
			SpiralSink.Speed = CommonSink.Speed;
			SpiralWay = note_Spiral_Right;
			bIsSpiral = true;
			break;

		case note_NormalSpiral:
			SpiralSink.Rotation = CommonSink.Rotation;
			SpiralSink.Speed = CommonSink.Speed;
			SpiralWay = note_NormalSpiral;
			bIsSpiral = true;
			break;

		case note_FourWaySpiral:
			SpiralSink.Rotation = CommonSink.Rotation;
			SpiralSink.Speed = CommonSink.Speed;
			SpiralWay = note_FourWaySpiral;
			bIsSpiral = true;
			break;

		case note_EightWaySpiral:
			SpiralSink.Rotation = CommonSink.Rotation;
			SpiralSink.Speed = CommonSink.Speed;
			SpiralWay = note_EightWaySpiral;
			bIsSpiral = true;
			break;

		default:
			break;
		}

		SinkFile >> SinkTime >> NoteType >> CommonSink.Rotation >> CommonSink.Speed;
	}


	if (bIsSpiral)		//달팽이노트
	{
		if (CurTime - IntervalTime > 10)
		{
			switch (SpiralWay)
			{
			case note_Spiral_Left:
				vNote.push_back(new CSprite_Note(note_Spiral_Left, SpiralSink.Rotation, 0.f, SpiralSink.Speed, 0.f));
				SpiralSink.Rotation -= CommonSink.Rotation_Rate;
				SpiralSink.Speed += CommonSink.Speed_Rate;
				break;

			case note_Spiral_Right:
				vNote.push_back(new CSprite_Note(note_Spiral_Right, SpiralSink.Rotation, 0.f, SpiralSink.Speed, 0.f));
				SpiralSink.Rotation += CommonSink.Rotation_Rate;
				SpiralSink.Speed += CommonSink.Speed_Rate;
				break;

			case note_NormalSpiral:
				vNote.push_back(new CSprite_Note(note_Normal, SpiralSink.Rotation, 0.f, SpiralSink.Speed, 0.f));
				SpiralSink.Rotation = GetMouseRotation();
				SpiralSink.Speed += CommonSink.Speed_Rate;
				break;

			case note_FourWaySpiral:
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 90, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 180, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 270, 0.f, SpiralSink.Speed, 0.f));

				SpiralSink.Speed += CommonSink.Speed_Rate;
				break;

			case note_EightWaySpiral:
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 90, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 180, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 270, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 45, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 135, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 225, 0.f, SpiralSink.Speed, 0.f));
				vNote.push_back(new CSprite_Note(note_FourWayNormal, SpiralSink.Rotation + 315, 0.f, SpiralSink.Speed, 0.f));

				SpiralSink.Speed += CommonSink.Speed_Rate;
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
			vNote.push_back(new CSprite_Note(note_Random, RandomSink.Rotation, 0.f, RandomSink.Speed, 0.f));
		}
	}

	if (CurTime >= ScoreTime)
	{
		ScoreTime += 100;

		Score += 100 * xScore;
		sprintf(strScore[0], "점수 %d", Score);
		ScoreBox[0].w = (strlen(strScore[0]) - 1) * 25;
		g_TextManager->ModifyText(strScore[0], 0);
	}

	if (CurTime >= xScoreTime)
	{
		if (xScore < 4.9f)
		{
			xScore += 0.1f;
			sprintf(strScore[1], "x%.1f", xScore);
			g_TextManager->ModifyText(strScore[1], 1);
		}
		xScoreTime += 1000;
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

	
	SDL_RenderCopy(g_DrawManager->pRenderer, SceneBGTexture, NULL, &SceneBGRect);

	for (int i = 0; i < vNote.size(); i++)			//노트들 업데이트
	{
		if (vNote[i] != nullptr)
		{
			SDL_RenderCopyEx(g_DrawManager->pRenderer, vNote[i]->GetSpriteTexture(), NULL, vNote[i]->GetSpriteRect(), vNote[i]->GetSpriteRotation(), vNote[i]->GetSpriteCenter(), *vNote[i]->GetSpriteFlip());
#ifdef _DEBUG
			SDL_SetRenderDrawColor(g_DrawManager->pRenderer, 255, 0, 0, 255);
			temprt = *vNote[i]->GetSpriteRect();

			x1 = temprt.x, x2 = temprt.w + temprt.x, x3 = temprt.x, x4 = temprt.w + temprt.x;
			y1 = temprt.y, y2 = temprt.y, y3 = temprt.h + temprt.y, y4 = temprt.h + temprt.y;
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x1, y1, x2, y2);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x1, y1, x3, y3);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x2, y2, x4, y4);
			SDL_RenderDrawLine(g_DrawManager->pRenderer, x3, y3, x4, y4);

			SDL_SetRenderDrawColor(g_DrawManager->pRenderer, 0, 0, 255, 255);
			g_EventManager->CheckCollition_by_Circle(vSprite[ePlayer], vNote[i]);
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

	
	vSprite[eBar]->Update();

}


void CScene_Game::Release()
{
	g_TextManager->SetColor(0, 0, 0);

	g_SoundManager->StopSound(eChannel1);
	g_SoundManager->DestroySound(eGameTheme);
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
	float offset_x = g_EventManager->g_Event.motion.x - (WINDOW_DEFAULT_W / 2 - 14);
	float offset_y = g_EventManager->g_Event.motion.y - (WINDOW_DEFAULT_H / 2 - 14);
	float radian = atan2(offset_y, offset_x);
	
	//Shark.x += cos(radian) * 5.0f;	// * -sinf(radian) * 5.0f;
	//Shark.y += -sin(radian) * 5.0f;	// * cosf(radian) * 5.0f;

	return (180.0f * radian) / M_PI;
}