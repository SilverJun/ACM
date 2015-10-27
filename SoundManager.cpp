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

	for (int i = 0; i < 5; i++)
	{
		pSound[i] = nullptr;
	}

	strcpy(path[eMainMenuSound], "./Resource/DJ_YOSHITAKA-VALLIS-NERIA.mp3");

	strcpy(path[eGameMusic1], "./Resource/Duelle_amp_CiRRO-Your_Addiction_Culture_Code_Remix.mp3");
	strcpy(path[eGameMusic2], "./Resource/English_Listening_Type_B.mp3");
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

	for (int i = 0; i < 5; i++)
	{
		if (pSound[i] != nullptr)
		{
			pSound[i]->release();
		}
	}
	
	pSystem->close();
}


void CSoundManager::MakeSound(eSound n)
{
	FMOD_RESULT f;
	f = pSystem->createSound(path[n],FMOD_DEFAULT, NULL, &pSound[n]);
	f;
}


void CSoundManager::DestroySound(eSound n)
{
	pSound[n]->release();
	pSound[n] = nullptr;
}


void CSoundManager::PlaySound(eChannel c, eSound n)
{
	FMOD_RESULT f;
	f = pSystem->playSound(FMOD_CHANNEL_FREE, pSound[n], false, &pChannel[c]);
	f;
}


void CSoundManager::PauseSound(eChannel c, bool b)
{
	pChannel[c]->setPaused(b);
}


void CSoundManager::StopSound(eChannel c)
{
	pChannel[c]->stop();
}

