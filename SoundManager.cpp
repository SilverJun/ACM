#include "StdAfx.h"
#include "SoundManager.h"


CSoundManager::CSoundManager(void)
{
	//System_Create(&pSystem);
}


CSoundManager::~CSoundManager(void)
{
}

void CSoundManager::Init()
{
	//pSystem->init(5/*최대 채널*/, FMOD_INIT_NORMAL, 0);

	//fmod c++
	//http://www.devpia.com/MAEUL/Contents/Detail.aspx?BoardID=6846&MAEULNO=878&no=40092
	//http://sayzy.blog.me/70071678225
	
}

void CSoundManager::Update()
{
	//pSystem->System::update();
}


void CSoundManager::Release()
{
	//pSystem->close();
}

