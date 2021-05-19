#pragma once
#include "ObjectSprite.h"

class FrogObjectSprite : public ObjectSprite
{
public:
	FrogObjectSprite()
	{
		this->texture = new sf::Texture();
		this->Load("GraphicsTest/frog.png");
	};
};