#pragma once
#include <SFML/Graphics.hpp>

class ObjectSprite : public sf::Sprite
{
public:
	float posX;
	float posY;
	int ID;
	sf::Texture* texture;
	std::string filename;
	
	ObjectSprite();
	void Load(std::string filename);
};