#pragma once
#include "Utilities.h"
#include "Point.h"
#include <map>
#include <list>
#include "Track.h"
#include "Player.h"
//#include <SFML/Graphics.hpp>
//#include "Enums.h"

//struct Track
//{
//	Point beginingOfTrack;
//	Point endOfTrack;
//	bool fromDownToUp;
//
//	sf::Clock *timer;
//	sf::Time elapsedTime;
//};

class PlaygroundLogic
{
public:
	PlaygroundLogic(Player* player);
	void GeneratePlayground(int widthOfWindow, int heightOfWindow, int numberOfTracks);

	std::list<Track> tracks;
	std::map<int, Point> frogStandingPoints;
	int height;
	int width;
private:
	void AddTrackBasedOnXCoordinate(int xCoordinate, int heightOfWindow, bool fromDownToUp);
};