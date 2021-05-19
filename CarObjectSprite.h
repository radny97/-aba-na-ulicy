#pragma once
#include "ObjectSprite.h"

class CarObjectSprite : public ObjectSprite
{
public:
	CarObjectSprite()
	{
		this->texture = new sf::Texture();
		this->Load("GraphicsTest/car from bottom.png");
	};

};