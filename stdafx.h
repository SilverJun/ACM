// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <cmath>
#include <mutex>

#include <conio.h>

//======== �߰� ���̺귯�� ��� ========
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <fmod.hpp>

enum eKey
{
	Up,
	Down,
	Left,
	Right,
	Space,
	esc,
	n1,
	n2,
	n3,
	n4,
};

enum eScene
{
	sMainMenu = 1,
	sMusicSelect,
	sGame,
	sRule,
	sScore,
	sCredit
};

enum eChannel
{ 
	eBGMChannel, 
	eChannel1, 
	eChannel2 
};

enum eSound
{
	eMainMenuSound,
	eMusicSelectSound,
	eEffectMusic,
	eGameMusic1,
	eGameMusic2
};


#define WINDOW_DEFAULT_W	1024
#define WINDOW_DEFAULT_H	768

using namespace std;
