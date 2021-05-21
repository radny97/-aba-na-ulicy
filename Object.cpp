#include "Object.h"

//Object::Object()
//{
//
//}

void Object::SetPosX(float x)
{
	this->posX = x;
}

void Object::SetPosY(float y)
{
	this->posY = y;
}

int Object::GenerateID()
{
	uint32_t id = reinterpret_cast<uint32_t>(this);
	return abs((int)id);
}