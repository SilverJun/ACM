#pragma once

#include "Singleton.h"

class CTextManager : public Singleton<CTextManager>
{
public:
	CTextManager();
	~CTextManager();

	TTF_Font* pTTF_Font;
	int point;
	SDL_Color color;
	SDL_Surface* pTTF_Surface[10];
	SDL_Texture* pTTF_Texture[10];
	SDL_Rect TTF_Rect[10];

	Uint16 string_han[10][256];
	bool string_han_idx_table[10];


	int CreateText(char *, int x, int y, int w, int h);
	int CreateText(char *, SDL_Rect *);
	void ModifyText(char *, int idx);
	void DestroyText(int idx);		
	void DestroyTextAll();

	void Init();
	void Update();
	void Render();
	void Release();

};

#define g_TextManager CTextManager::GetInstance()