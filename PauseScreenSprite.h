#pragma once
#include "ObjectSprite.h"

class PauseScreenSprite : public ObjectSprite
{
public:
	PauseScreenSprite()
	{
		this->texture = new sf::Texture();
		this->SetTextureFromFile("Graphics/pauseScreen.png");
	};
};


