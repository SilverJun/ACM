#include "stdafx.h"

#include "DrawManager.h"
#include "EventManager.h"

#include "Sprite.h"
#include "Sprite_Note.h"


CSprite_Note::CSprite_Note() : CSprite("Note", 20, 20, 0, 0, 20, 20)
{
	//SetSpriteImage("./Resource/Note.png");
}

CSprite_Note::CSprite_Note(eNote type, float Rotation, float Rotation_Rate, int Speed, int Speed_Rate) : CSprite("Note", 20, 20, 0, 0, 20, 20)
{
	NoteType = type;

	int NoteColor = rand() % 8;
	
	switch (type)
	{
	case note_Normal:
	case note_FourWayNormal:
		SpriteTexture = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, g_DrawManager->NormalNoteSurface);
		SetSpriteCenter(39, 39);
		SpriteRect = { 0, 0, 39, 39 };
		break;
	case note_Spiral_Left:
	case note_Spiral_Right:
		SpriteTexture = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, g_DrawManager->SpiralNoteSurface);
		SetSpriteCenter(44, 44);
		SpriteRect = { 0, 0, 44, 44 };
		break;
	case note_Random:
		SpriteTexture = SDL_CreateTextureFromSurface(g_DrawManager->pRenderer, g_DrawManager->Note[NoteColor]);
		SetSpriteCenter(20, 20);
		SpriteRect = { 0, 0, 20, 20 };
		break;
	default:
		break;
	}

	SetSpriteRect((WINDOW_DEFAULT_W / 2 - center.x), (WINDOW_DEFAULT_H / 2 - center.y));
	
	SetSpriteRotation(Rotation);
	
	this->Speed = Speed;
	this->Speed_Rate = Speed_Rate;
	this->Rotation_Rate = Rotation_Rate;
	radian = rotation * (M_PI / 180);
}


CSprite_Note::~CSprite_Note()
{
	
}


void CSprite_Note::Update()
{
	SpriteRect.x += Speed * cosf(radian);
	SpriteRect.y += Speed * sinf(radian);

	//rotation += Rotation_Rate;
	//Speed += Speed_Rate;
}


eNote CSprite_Note::GetNoteType()
{
	return NoteType;
}

