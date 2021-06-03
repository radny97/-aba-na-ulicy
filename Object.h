#pragma once
#include "Utilities.h"
#include "Point.h"
#include "Enums.h"
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>

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

	virtual void UpdateObject() {};
	virtual void Jump(float destination) {};
	virtual void Death(float XcoordinateOfStart, int scoreToDelete) {};
	//virtual void Move() {};
	virtual bool CheckIfCollisionPointIsInBounds(Point point) { return true; };

	sf::Clock timer;
	sf::Time elapsedTime;

	bool collisional;
	bool temporaryNonCollisional;
	int velocity;

protected:
	int GenerateID();
	
};