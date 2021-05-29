#pragma once
#include "ObjectSprite.h"

class CarObjectSprite : public ObjectSprite
{
public:
	CarObjectSprite() {};
	CarObjectSprite(bool fromDownToUp)
	{
		int randomNumber = rand() % 5;
		if (fromDownToUp == true)
		{
			this->texture = new sf::Texture();
			this->SetTextureFromFile("GraphicsTest/carFromBottom" + std::to_string(randomNumber) + ".png");
		}
		else
		{
			this->texture = new sf::Texture();
			this->SetTextureFromFile("GraphicsTest/carFromTop" + std::to_string(randomNumber) + ".png");
		}
	};

};