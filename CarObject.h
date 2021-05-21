#pragma once
#include "Object.h"

class CarObject : public Object
{
public:
	CarObject() {};
	CarObject(int x, int y, bool fromDownToUp)
	{
		this->posX = x - (Utilities::carImageSizeX / 2);
		this->posY = y - (Utilities::carImageSizeY / 2);
		this->type = "car";
		this->ID = GenerateID();
		this->fromDownToUp = fromDownToUp;
	}
	void Move(int velocity) override;

	bool fromDownToUp;
};