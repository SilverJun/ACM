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
#include <unordered_map>

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
	n4
};

enum eScene
{
	sMainMenu = 1,
	sMusicSelect,
	sGame,
	sGameEnd,
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
	eGameTheme
};

enum eNote
{
	note_Normal,
	note_FourWayNormal,
	note_Spiral_Left,
	note_Spiral_Right,
	note_Random,
	note_NormalSpiral,
	note_FourWaySpiral,
	note_EightWaySpiral
};

enum eSong
{
	eMainMenu,
	eYour_Addiction,
	eEnglish_Listening,
	eCircles,
	eEffect_Click,
	eEffect_ComboBreak,
	eEffect_GameEnd
};


#define WINDOW_DEFAULT_W	1280
#define WINDOW_DEFAULT_H	960

using namespace std;
