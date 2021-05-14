#include "Object.h"

//Object::Object()
//{
//
//}

int Object::GenerateID()
{
	uint32_t id = reinterpret_cast<uint32_t>(this);
	return id;
}

std::string Object::GetStringWithTypeAndID()
{
	return this->type + std::to_string(this->ID);
}