#include "stdafx.h"
#include "Scene_Credit.h"

#include "TextManager.h"
#include "EventManager.h"
#include "SceneManager.h"


CScene_Credit::CScene_Credit() : CScene(sCredit)
{
	CreditBox[0] = { 100, 200, 0, 40 };
	CreditBox[1] = { 100, 270, 0, 40 };
	CreditBox[2] = { 100, 320, 0, 40 };
	CreditBox[3] = { 100, 370, 0, 40 };
	CreditBox[4] = { 100, 420, 0, 40 };

	strcpy(CreditString[0], "�۵� ACM ������, 1.0 version");
	strcpy(CreditString[1], "��ȹ : ������");
	strcpy(CreditString[2], "���α׷��� : ������");
	strcpy(CreditString[3], "�׷��� : ��ȣ��");
	strcpy(CreditString[4], "�ƹ�Ű�� ���� �ּ���!");

	CreditBox[0].w = (strlen(CreditString[0]) - 1) * 15;
	CreditBox[1].w = (strlen(CreditString[1]) - 1) * 15;
	CreditBox[2].w = (strlen(CreditString[2]) - 1) * 15;
	CreditBox[3].w = (strlen(CreditString[3]) - 1) * 15;
	CreditBox[4].w = (strlen(CreditString[4]) - 1) * 15;
}


CScene_Credit::~CScene_Credit()
{
	Release();
}


void CScene_Credit::Init()
{
	for (int i = 0; i < 5; i++)
	{
		g_TextManager->CreateText(CreditString[i], &CreditBox[i]);
	}
}


void CScene_Credit::Update()
{
	if (g_EventManager->g_Event.type == SDL_KEYDOWN)
	{
		g_SceneManager->SetScene(sMainMenu);
	}
}


void CScene_Credit::Release()
{
	g_TextManager->DestroyTextAll();
}

