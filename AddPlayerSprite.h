#pragma once
#include <SFML/Graphics.hpp>

class AddPlayerSprite : public sf::Sprite
{
public:
	AddPlayerSprite()
	{
		this->texture = new sf::Texture();
		this->SetTextureFromFile("Graphics/addPlayerScreen.png");
	};

	void SetTextureFromFile(std::string filename);
private:
	sf::Texture* texture;
};

