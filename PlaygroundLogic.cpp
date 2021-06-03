#include "PlaygroundLogic.h"

PlaygroundLogic::PlaygroundLogic()
{
	this->width = Utilities::screenResolutionX;
	this->height = Utilities::screenResolutionY;

	this->GeneratePlayground(this->width, this->height, Player::getInstance().GetScore());
}

void PlaygroundLogic::GeneratePlayground(int widthOfWindow, int heightOfWindow, int playerScore)
{
	//tu bêdzie jakieœ losowanie wed³ug levela gry
	int numberOfTracks;// = numberOfTracks;
	if (playerScore < 4)
	{
		numberOfTracks = 2;
	}
	else if (playerScore < 10)
	{
		numberOfTracks = 4;
	}
	else if (playerScore < 18)
	{
		numberOfTracks = 6;
	}
	else if (playerScore < 28)
	{
		numberOfTracks = 8;
	}
	else
	{
		numberOfTracks = 10;
	}


	int widthOfTrack = Utilities::widthOfTrack;
	int widthOfSpaceBetweenTracks = Utilities::widthOfSpaceBetweenTracks;

	std::list<int> xCoordinatesOfFrogStandingPoints;

	//dodaj trasê maj¹c punkt w po³owie wysokoœci planszy

	int xCoordinateOfMiddleOfPlayground = widthOfWindow / 2;
	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground);

	int xCoordinateDifference = (widthOfSpaceBetweenTracks + widthOfTrack) / 2;

	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground + xCoordinateDifference);
	AddTrackBasedOnXCoordinate(xCoordinateOfMiddleOfPlayground + xCoordinateDifference, heightOfWindow, true);

	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground - xCoordinateDifference);
	AddTrackBasedOnXCoordinate(xCoordinateOfMiddleOfPlayground - xCoordinateDifference, heightOfWindow, false);

	for (int i = 0; i < (numberOfTracks/2)-1; i++)
	{
		xCoordinateDifference += widthOfTrack;

		xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground + xCoordinateDifference);
		AddTrackBasedOnXCoordinate(xCoordinateOfMiddleOfPlayground + xCoordinateDifference, heightOfWindow, true);

		xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground - xCoordinateDifference);
		AddTrackBasedOnXCoordinate(xCoordinateOfMiddleOfPlayground - xCoordinateDifference, heightOfWindow, false);
	}
	xCoordinateDifference += (widthOfSpaceBetweenTracks + widthOfTrack) / 2;
	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground + xCoordinateDifference);
	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground - xCoordinateDifference);

	xCoordinatesOfFrogStandingPoints.sort();
	int iteratorOfPoint = 0;
	for (auto const& iteratorOfxCoordinate : xCoordinatesOfFrogStandingPoints) 
	{
		this->frogStandingPoints.insert(std::make_pair(iteratorOfPoint,Point(iteratorOfxCoordinate, (heightOfWindow / 2))));
		iteratorOfPoint++;
	}

}

void PlaygroundLogic::AddTrackBasedOnXCoordinate(int xCoordinate, int heightOfWindow, bool fromDownToUp)
{
	int xDifferenceFromParameterCoordinate;
	xDifferenceFromParameterCoordinate = (heightOfWindow / 2) / Utilities::trackGrade; //k¹t nachylenia

	//Track newTrack = new Track();

	if (fromDownToUp == true)
	{
		Track* newTrack = new Track(Point(xCoordinate - xDifferenceFromParameterCoordinate, heightOfWindow),
			Point(xCoordinate + xDifferenceFromParameterCoordinate, 0),
			fromDownToUp);
		/*Point(xCoordinate - xDifferenceFromParameterCoordinate, heightOfWindow),
		Point(xCoordinate + xDifferenceFromParameterCoordinate, 0),
		fromDownToUp,
		};*/
		this->tracks.push_back(*newTrack);
	}
	else
	{
		Track* newTrack = new Track(Point(xCoordinate + xDifferenceFromParameterCoordinate, 0),
			Point(xCoordinate - xDifferenceFromParameterCoordinate, heightOfWindow),
			fromDownToUp);
		/*Point(xCoordinate + xDifferenceFromParameterCoordinate, 0),
		Point(xCoordinate - xDifferenceFromParameterCoordinate, heightOfWindow),
		fromDownToUp,
		};*/
		this->tracks.push_back(*newTrack);
	}
}