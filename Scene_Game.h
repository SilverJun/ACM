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
	CScene_Game(eSound);
	~CScene_Game();

	void addNote(CSprite_Note *);
	
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	float GetMouseRotation();

private:
	int Score;

	vector<CSprite_Note *> vNote;
	
	clock_t SinkTime, GameEndTime, CurTime, IntervalTime, ScoreTime, xScoreTime;
	float xScore;
	//���ھ� ����. 1~2����. 5�ʰ� 0.1�� �ö�, �ǰݽ� -0.2
	int NoteType;

	int SprialWay;

	//======SinkData===========
	NoteData CommonSink;

	NoteData NormalSink;
	NoteData FourWaySink;
	NoteData SprialSink;

	NoteData RandomSink;
	//=========================

	bool bIsSprial;
	bool bIsRandomNote;
	bool bIsGameEnd;

	fstream SinkFile, ScoreFile;

	char strScore[128];
	SDL_Rect ScoreBox;

	eSound ThisSong;
};

