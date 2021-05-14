#pragma once
#include <string>

class Object
{
public:
	Object() {};

	std::string GetStringWithTypeAndID();

	float posX;
	float posY;
	std::string type;
	int ID;

protected:
	int GenerateID();
};