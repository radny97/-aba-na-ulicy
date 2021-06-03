#include "ObjectSprite.h"

ObjectSprite::ObjectSprite()
{

}

void ObjectSprite::SetTextureFromFile(std::string filename)
{
	this->texture->loadFromFile(filename);
	this->setTexture(*this->texture);
}