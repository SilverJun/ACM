#include "stdafx.h"

#include "DrawManager.h"
#include "EventManager.h"

#include "Sprite.h"
#include "Sprite_Note.h"


CSprite_Note::CSprite_Note() : CSprite("Note", 20, 20, 0, 0, 20, 20)
{
	SetSpriteImage("./Resource/Note.png");
}

CSprite_Note::CSprite_Note(int Rotation) : CSprite("Note", 20, 20, 0, 0, 20, 20)
{
	SetSpriteImage("./Resource/Note.png");
	SetSpriteRotation(float(Rotation));
}


CSprite_Note::~CSprite_Note()
{
	
}


void CSprite_Note::Update()
{


}


