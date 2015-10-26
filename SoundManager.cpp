#include "StdAfx.h"
#include "SoundManager.h"


CSoundManager::CSoundManager(void)
{
	System_Create(&pSystem);
}


CSoundManager::~CSoundManager(void)
{
}

void CSoundManager::Init()
{
	pSystem->init(3, FMOD_INIT_NORMAL, 0);

	//fmod c++
	//http://www.devpia.com/MAEUL/Contents/Detail.aspx?BoardID=6846&MAEULNO=878&no=40092
	//http://sayzy.blog.me/70071678225
	
	//eMainMenuSound,
	//eMusicSelectSound,
	//eEffectMusic,
	//eGameMusic1,
	//eGameMusic2

	path[eGameMusic1] = "./Resource/Duelle_amp_CiRRO-Your_Addiction_Culture_Code_Remix.mp3";
	path[eGameMusic2] = "./Resource/English_Listening_Type_B.mp3";
}

void CSoundManager::Update()
{
	pSystem->update();
}


void CSoundManager::Release()
{
	for (int i = 0; i < 3; i++)
	{
		pChannel[i]->stop();
	}
	
	pSystem->close();
}


void CSoundManager::MakeSound(eSound n)
{
	pSystem->createSound(path[n],FMOD_DEFAULT, NULL, &pSound[n]);
}


void CSoundManager::DestroySound(eSound n)
{
	pSound[n]->release();
}


void CSoundManager::PlaySound(eChannel c, eSound n)
{
	pSystem->playSound(FMOD_CHANNEL_FREE, pSound[n], false, &pChannel[c]);
}


void CSoundManager::PauseSound(eChannel c, bool b)
{
	pChannel[c]->setPaused(b);
}


void CSoundManager::StopSound(eChannel c)
{
	pChannel[c]->stop();
}

