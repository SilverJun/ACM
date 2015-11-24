#include "stdafx.h"

#include "EventManager.h"

#include "Sprite_Player.h"


CSprite_Player::CSprite_Player() : CSprite("Player", 29, 29, 5, 5, 19, 19)
{
	SetSpriteImage("Player.png");
}


CSprite_Player::~CSprite_Player()
{

}


void CSprite_Player::Update()
{
	SpriteMask.x = SpriteRect.x + 5;
	SpriteMask.y = SpriteRect.y + 5;
}

