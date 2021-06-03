#pragma once
#include "ObjectSprite.h"

class PlaygroundSprite : public ObjectSprite
{
public:
	PlaygroundSprite()
	{
		this->texture = new sf::Texture();
		this->SetTextureFromFile("Graphics/grassFullHD.png");
	};
};



