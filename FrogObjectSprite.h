#pragma once
#include "ObjectSprite.h"

class FrogObjectSprite : public ObjectSprite
{
public:
	FrogObjectSprite()
	{
		this->texture = new sf::Texture();
		this->SetTextureFromFile("Graphics/frogNormalStanding.png");
	};

	void SetTextureFromType(int type) override;
};