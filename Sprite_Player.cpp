#include "stdafx.h"

#include "EventManager.h"


#include "Sprite_Player.h"


CSprite_Player::CSprite_Player() : CSprite("Player", 29, 29, 1, 1, 27, 27)
{
	SetSpriteImage("./Resource/Player.png");
}


CSprite_Player::~CSprite_Player()
{

}


void CSprite_Player::Update()
{
	
	
}

