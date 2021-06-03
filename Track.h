#pragma once
#include "Point.h"
#include <SFML/Graphics.hpp>

class Track
{
public:
	Track() {};
	Track(Point begining, Point end, bool direction) {
		this->beginingOfTrack = begining;
		this->endOfTrack = end;
		this->fromDownToUp = direction;
		timer.restart();
		this->randomNumber = rand() % 1000;
	};

	Point beginingOfTrack;
	Point endOfTrack;
	bool fromDownToUp;

	int randomNumber;
	
	sf::Clock timer;
	sf::Time elapsedTime;
};

