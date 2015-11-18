// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
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

//======== 추가 라이브러리 헤더 ========
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
