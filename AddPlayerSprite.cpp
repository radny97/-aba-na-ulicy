#include "AddPlayerSprite.h"

void AddPlayerSprite::SetTextureFromFile(std::string filename)
{
	this->texture->loadFromFile(filename);
	this->setTexture(*this->texture);
}