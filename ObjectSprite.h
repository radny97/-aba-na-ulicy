#pragma once
#include <SFML/Graphics.hpp>
#include "Enums.h"

class ObjectSprite : public sf::Sprite
{
public:
	int posX;
	int posY;
	int ID;
	sf::Texture* texture;
	std::string filename;

	int versionOfTexture;
	
	ObjectSprite();
	void SetTextureFromFile(std::string filename);
	virtual void SetTextureFromType(int type) {};
};