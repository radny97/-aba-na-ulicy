#pragma once
#include "Utilities.h"
#include "Point.h"
#include <map>
#include <list>

struct Track
{
	Point beginingOfTrack;
	bool fromDownToUp;
};

class Playground
{
public:
	Playground();
	void GeneratePlayground(int widthOfWindow, int heightOfWindow);

	std::list<Track> tracks;
	std::map<int, Point> frogStandingPoints;
private:
	void AddTrackBasedOnXCoordinate(int xCoordinate, int heightOfWindow, bool fromDownToUp);
	int height;
	int width;
};