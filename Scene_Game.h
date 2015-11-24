#pragma once
#include "Scene.h"

#include "Sprite_Note.h"

typedef struct _NoteData
{
	float Rotation, Rotation_Rate;
	int Speed, Speed_Rate;
	int interval;
}NoteData;

class CScene_Game : public CScene
{
public:
	CScene_Game();
	~CScene_Game();

	void addNote(CSprite_Note *);
	
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	float GetMouseRotation();

	void SetSong(eSong Song);

private:
	int Score;

	vector<CSprite_Note *> vNote;
	
	clock_t SinkTime, GameEndTime, CurTime, IntervalTime, ScoreTime, xScoreTime;
	float xScore;
	//스코어 배율. 1~2까지. 5초간 0.1씩 올라감, 피격시 -0.2
	int NoteType;

	int SpiralWay;

	//======SinkData===========
	NoteData CommonSink;

	NoteData NormalSink;
	NoteData FourWaySink;
	NoteData SpiralSink;

	NoteData RandomSink;
	//=========================

	bool bIsSpiral;
	bool bIsRandomNote;
	bool bIsGameEnd;

	fstream SinkFile, ScoreFile;

	char strScore[2][128];
	SDL_Rect ScoreBox[2];

	eSong ThisSong;

	
};

