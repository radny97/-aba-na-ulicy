#pragma once
#include "Utilities.h"
#include <string>
#include <cmath>

class Object
{
public:
	Object() {};
	virtual void SetPosX(float x);
	virtual void SetPosY(float y);

	float posX;
	float posY;
	std::string type;
	int ID;
	virtual void Move(int velocity) {};

protected:
	int GenerateID();
};