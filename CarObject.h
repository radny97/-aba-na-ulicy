#pragma once
#include "Object.h"

class CarObject : public Object
{
public:
	CarObject() {};
	CarObject(int x, int y, bool fromDownToUp)
	{
		int randomNumber = rand() % 5 + 3;

		if (fromDownToUp == true)
		{
			this->posX = x - (Utilities::carImageSizeX / 2);
			this->posY = y - (Utilities::carImageSizeY / 2);
		}
		else
		{
			this->posX = x;// -(Utilities::carImageSizeX / 2);
			this->posY = y - (Utilities::carImageSizeY);
		}
		
		this->type = "car";
		this->ID = GenerateID();
		this->fromDownToUp = fromDownToUp;
		this->velocity = randomNumber;// slowVelocity;

		this->collisional = true;
		UpdateCollisionPoints();
	}

	bool CheckIfCollisionPointIsInBounds(Point point) override;
	void Move();
	void UpdateObject() override;

	Point *frontCollisionPoint; //middle of front bumper of car
	Point *backCollisionPoint; //middle of back bumper of car

	sf::Clock timerForCollisions;
	sf::Time elapsedTimeForCollisions;

	bool fromDownToUp;


private:
	void UpdateCollisionPoints();
};