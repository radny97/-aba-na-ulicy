#pragma once
#include "Object.h"

class CarObject : public Object
{
public:
	CarObject() {};
	CarObject(float x, float y)
	{
		this->posX = x;
		this->posY = y;
		this->type = "car";
		this->ID = GenerateID();
	}
};