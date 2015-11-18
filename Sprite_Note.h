#pragma once

class CSprite_Note : public CSprite
{
public:
	CSprite_Note();
	CSprite_Note(eNote type, float Rotation, float Rotation_Rate, int Speed, int Speed_Rate);
	~CSprite_Note();

	virtual void Update() override;

	eNote GetNoteType();

private:
	float Rotation_Rate;
	int Speed;
	int Speed_Rate;
	//SDL_Point pos[4];
	float radian;

	eNote NoteType;
};

