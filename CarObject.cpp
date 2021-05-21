#include "CarObject.h"

//CarObject::CarObject()
//{
//}

void CarObject::Move(int velocity)
{
	if (this->fromDownToUp == false)
	{
		this->posY += (sqrt(velocity) * Utilities::trackGrade);
		this->posX -= (sqrt(velocity) * 1);
	}
	else
	{
		this->posY -= (sqrt(velocity) * Utilities::trackGrade);
		this->posX += (sqrt(velocity) * 1);
	}
}