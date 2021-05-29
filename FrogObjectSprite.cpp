#include "FrogObjectSprite.h"

//FrogObjectSprite::FrogObjectSprite()
//{
//}

void FrogObjectSprite::SetTextureFromType(int type)
{

	if (type != this->versionOfTexture)
	{
		switch (type)
		{
		case (int)StateOfFrog::normalStanding:
			this->texture->loadFromFile("GraphicsTest/frogNormalStanding.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::jumpForwards:
			this->texture->loadFromFile("GraphicsTest/frogJumpForwards.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::jumpBackwards:
			this->texture->loadFromFile("GraphicsTest/frogJumpBackwards.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::beforeAfterJump:
			this->texture->loadFromFile("GraphicsTest/frogBeforeAfterJump.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::death:
			this->texture->loadFromFile("GraphicsTest/frogDeath.png");
			this->setTexture(*this->texture);
			break;
		default:
			break;
		}
	}
	
	this->versionOfTexture = type;
}