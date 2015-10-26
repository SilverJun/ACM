#pragma once

typedef enum tageSpriteDirection{cUP, cDOWN, cLEFT, cRIGHT, cUNKNOWN} SpriteDirection;

class CSprite
{
protected:
	SDL_Rect SpriteRect;
	SDL_Rect SpriteMask;
	int x, y;
	SDL_Point center;
	
	SpriteDirection SpriteDir;

	float rotation;
	SDL_RendererFlip flip;

	SDL_Surface * SpriteImage;
	SDL_Texture * SpriteTexture;
	char * SpriteName;
	
public:
	CSprite();
	CSprite(char *, int w, int h, int mx,int my,int mw, int mh);
	virtual ~CSprite();

	void SetSpriteImage(char *);

	void SetSpriteRect(int,int);
	void SetSpriteX(int);
	void SetSpriteY(int);
	void SetSpriteRotation(float); //회전도 지정
	void SetSpriteRotate(int);	//회전도 변화
	void SetSpriteCenter(int x, int y);

	SDL_Rect* GetSpriteRect();
	SDL_Rect* GetSpriteMask();
	int GetSpriteX();
	int GetSpriteY();
	float GetSpriteRotation();
	SDL_Texture * GetSpriteTexture();
	char * GetSpriteName();
	SDL_Point * GetSpriteCenter();
	SDL_RendererFlip * GetSpriteFlip();

	SpriteDirection GetSpriteDirection();

	virtual void Update() = 0;
	
};

