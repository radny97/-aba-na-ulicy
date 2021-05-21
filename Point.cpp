#include "Point.h"

Point::Point(int x, int y)
{
	this->coordinateX = x;
	this->coordinateY = y;
}

void Point::SetValues(int x, int y)
{
	this->coordinateX = x;
	this->coordinateY = y;
}