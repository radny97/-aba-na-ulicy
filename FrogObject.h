#pragma once
#include "Object.h"
#include "Player.h"

class FrogObject : public Object
{
public:
	FrogObject() {};
	FrogObject(float x, float y, Player* player)
	{
		this->posX = x - (Utilities::frogImageSizeX / 2);
		this->posY = y - (Utilities::frogImageSizeY / 2);
		this->player = player;

		this->type = "frog";
		this->ID = GenerateID();
		this->collisional = true;
		this->velocity = 0;
		this->stateOfFrog = StateOfFrog::normalStanding;
	}
	bool CheckIfCollisionPointIsInBounds(Point point) override;
	void SetPosX(float x) override;

	void UpdateObject() override;
	void Move();
	void Jump(float destination) override;
	void Death(float XcoordinateOfStart) override;

	StateOfFrog stateOfFrog;
	Player* player;

private:
	bool activateJump;
	bool activateDeath;
	float destinationOfJump;
};