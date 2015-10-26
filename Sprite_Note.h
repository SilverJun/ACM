#pragma once
class CSprite_Note : public CSprite
{
public:
	CSprite_Note();
	CSprite_Note(int Rotation);
	~CSprite_Note();

	virtual void Update() override;

private:
	int x_variation;
	int y_variation;
	//SDL_Point pos[4];

};

