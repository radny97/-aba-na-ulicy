#pragma once
#include "Object.h"

class FrogObject : public Object
{
public:
	FrogObject() {};
	FrogObject(float x, float y)
	{
		this->posX = x;
		this->posY = y;
		this->type = "frog";
		this->ID = GenerateID();
	}
};