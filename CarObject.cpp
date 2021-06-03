#include "CarObject.h"

//CarObject::CarObject()
//{
//}

void CarObject::UpdateObject()
{
	if (this->velocity <= 0)
		this->velocity = 1;

	//mo¿e siê jeszcze uda zapanowaæ nad blokuj¹cymi siê autami ustawiaj¹c previousVelocity

	//losowanie zmiany prêdkoœci 
	this->elapsedTime = this->timer.getElapsedTime();
	if (this->collisional == false && this->elapsedTime.asMilliseconds() > 500)
	{
		int random = rand() % 30;
		int parameter = 6 - this->velocity; //wspó³czynnik
		if (random < pow(parameter,2))
		{
			if (parameter < 0)
				this->velocity--;
			else
				this->velocity++;
		}

		this->timer.restart();
	}

	

	if (this->temporaryNonCollisional == true)
	{
		this->collisional = false;
		this->timerForCollisions.restart();
		this->temporaryNonCollisional = false;
	}
	this->elapsedTimeForCollisions = this->timer.getElapsedTime();
	if (this->collisional == false && this->elapsedTimeForCollisions.asMilliseconds() > 50)
	{
		this->collisional = true;
	}




	Move();
}

void CarObject::Move()
{
	if (this->fromDownToUp == false)
	{
		this->posY += (sqrt(this->velocity) * Utilities::trackGrade);
		this->posX -= (sqrt(this->velocity) * 1);
	}
	else
	{
		this->posY -= (sqrt(this->velocity) * Utilities::trackGrade);
		this->posX += (sqrt(this->velocity) * 1);
	}
	UpdateCollisionPoints();
}

bool CarObject::CheckIfCollisionPointIsInBounds(Point point)
{
	//carObject have wider Y bounds because cars cannot touch each other
	if (this->fromDownToUp == true
		&& point.coordinateX > this->posX
		&& point.coordinateX < this->posX + Utilities::carImageSizeX
		&& point.coordinateY > this->posY// - (Utilities::carImageSizeY / 4)
		&& point.coordinateY < this->posY + Utilities::carImageSizeY + (Utilities::carImageSizeY / 2)
		) {
		return true;
	}
	else if (this->fromDownToUp == false
		&& point.coordinateX > this->posX
		&& point.coordinateX < this->posX + Utilities::carImageSizeX
		&& point.coordinateY > this->posY - (Utilities::carImageSizeY / 2)
		&& point.coordinateY < this->posY + Utilities::carImageSizeY// + (Utilities::carImageSizeY / 4)
		) {
		return true;
	}
	return false;
}

void CarObject::UpdateCollisionPoints()
{
	this->frontCollisionPoint = new Point(this->posX + ((3 * Utilities::carImageSizeX) / 4), this->posY);
	this->backCollisionPoint = new Point(this->posX + (Utilities::carImageSizeX / 4), this->posY + Utilities::carImageSizeY);


}