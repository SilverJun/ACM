#include "stdafx.h"

#include "ResourceManager.h"


CResourceManager::CResourceManager()
{
	key = "silver5609";
}


CResourceManager::~CResourceManager()
{
	Release();
}


void CResourceManager::Init()
{
	// Zip 파일을 로드한다.
	hz = OpenZip("Resource.zip", key);
	mem = nullptr;
	rw = nullptr;
	
	NormalNoteSurface = IMG_Load_RW(LoadItem("NormalNote.png"), 0);
	RandomNoteSurface = IMG_Load_RW(LoadItem("RandomNote.png"), 0);
	SpiralNoteSurface = IMG_Load_RW(LoadItem("SpiralNote.png"), 0);

	Note[0] = IMG_Load_RW(LoadItem("note__1.png"), 0);
	Note[1] = IMG_Load_RW(LoadItem("note__2.png"), 0);
	Note[2] = IMG_Load_RW(LoadItem("note__3.png"), 0);
	Note[3] = IMG_Load_RW(LoadItem("note__4.png"), 0);
	Note[4] = IMG_Load_RW(LoadItem("note__5.png"), 0);
	Note[5] = IMG_Load_RW(LoadItem("note__6.png"), 0);
	Note[6] = IMG_Load_RW(LoadItem("note__7.png"), 0);
	Note[7] = IMG_Load_RW(LoadItem("note__8.png"), 0);
}


void CResourceManager::Release()
{
	for (int i = 0; i < 8; i++)
	{
		SDL_FreeSurface(Note[i]);
	}

	SDL_FreeSurface(SpiralNoteSurface);
	SDL_FreeSurface(RandomNoteSurface);
	SDL_FreeSurface(NormalNoteSurface);

	for (int i = vRememberSurface.size() - 1; i >= 0; i--)
	{
		SDL_FreeSurface(vRememberSurface[i]);
		vRememberSurface.pop_back();
	}

	CloseZip(hz);
}


SDL_RWops *CResourceManager::LoadItem(char *name)
{
	// Zip에서 찾고자 하는 파일을 검색한다.
	ZRESULT z;
	z = FindZipItem(hz, name, false, &index, &ze);
	// 압축울 풀 메모리 공간을 할당한다.
	//if (mem != nullptr)
	//{
	//	free(mem);
	//}
	mem = malloc(ze.unc_size);
	// 메모리 공간상에 압축을 푼다.
	UnzipItem(hz, index, mem, ze.unc_size);
	// 압축푼곳으로부터 SDL_RWops를 생성한다
	//if (rw != nullptr)
	//{
	//	SDL_FreeRW(rw);
	//}
	rw = SDL_RWFromMem(mem, ze.unc_size);

	return rw;
	//// RWops로 이미지를 로드한다
	//return IMG_Load_RW(rw, 0);
}


int CResourceManager::addRememberSurface(SDL_Surface *s)
{
	vRememberSurface.push_back(s);
	return vRememberSurface.size() - 1;
}

//hitomi

