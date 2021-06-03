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
			this->texture->loadFromFile("Graphics/frogNormalStanding.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::wait:
			this->texture->loadFromFile("Graphics/frogNormalStanding.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::jumpForwards:
			this->texture->loadFromFile("Graphics/frogJumpForwards.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::jumpBackwards:
			this->texture->loadFromFile("Graphics/frogJumpBackwards.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::beforeAfterJump:
			this->texture->loadFromFile("Graphics/frogBeforeAfterJump.png");
			this->setTexture(*this->texture);
			break;
		case (int)StateOfFrog::death:
			this->texture->loadFromFile("Graphics/frogDeath.png");
			this->setTexture(*this->texture);
			break;
		default:
			break;
		}
	}
	
	this->versionOfTexture = type;
}