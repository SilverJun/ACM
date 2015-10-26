#include "stdafx.h"
#include "Sprite_SpawnNote.h"


CSprite_SpawnNote::CSprite_SpawnNote() : CSprite("SpawnNote", 100,100,0,0,100,100)
{
	SetSpriteImage("./Resource/SpawnNote.png");
	SetSpriteRect((WINDOW_DEFAULT_W / 2 - 50),(WINDOW_DEFAULT_H / 2 - 50));
}


CSprite_SpawnNote::~CSprite_SpawnNote()
{
}


void CSprite_SpawnNote::Update()
{

}
