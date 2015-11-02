#include "stdafx.h"

#include "DrawManager.h"
#include "EventManager.h"

#include "Sprite.h"
#include "Sprite_Note.h"


CSprite_Note::CSprite_Note() : CSprite("Note", 20, 20, 0, 0, 20, 20)
{
	SetSpriteImage("./Resource/Note.png");
}

CSprite_Note::CSprite_Note(float Rotation, float Rotation_Rate, int Speed, int Speed_Rate) : CSprite("Note", 20, 20, 0, 0, 20, 20)
{
	SetSpriteRect((WINDOW_DEFAULT_W / 2 - 10), (WINDOW_DEFAULT_H / 2 - 10));
	SetSpriteImage("./Resource/Note.png");
	SetSpriteRotation(Rotation);
	SetSpriteCenter(10, 10);
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


