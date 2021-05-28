#include "CarObject.h"

//CarObject::CarObject()
//{
//}

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
	if (point.coordinateX > this->posX
		&& point.coordinateX < this->posX + Utilities::carImageSizeX
		&& point.coordinateY > this->posY - (Utilities::carImageSizeY / 6)
		&& point.coordinateY < this->posY + Utilities::carImageSizeY + (Utilities::carImageSizeY / 6)
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