#include "GameGraphics.h"

GameGraphics::GameGraphics()
{
	
}

void GameGraphics::Update(sf::RenderWindow* window, std::unordered_map<std::string, Object*> allModels)
{
	std::regex wzorzec("\d+$");
	for (auto& iterator : allModels) //przejdz po liscie z zewn¹trz
	{
		if (!this->listOfObjectSprites.empty())
		{
			for (const auto& i : this->listOfObjectSprites) //przejdz po liscie wewnatrz
			{
				if (iterator.second->ID != i->ID)
				{
					std::smatch wynik; // tutaj bêdzie zapisany wynik
					if (std::regex_search(iterator.first, wynik, wzorzec))
					{
						if (wynik[0] == "frog")
						{
							ObjectSprite* frogObjectSprite = new FrogObjectSprite();
							frogObjectSprite->posX = iterator.second->posX;
							frogObjectSprite->posY = iterator.second->posY;
							frogObjectSprite->ID = iterator.second->ID;
							this->listOfObjectSprites.push_front(frogObjectSprite);
						}
						else if (wynik[0] == "car")
						{
							ObjectSprite* carObjectSprite = new CarObjectSprite();
							carObjectSprite->posX = iterator.second->posX;
							carObjectSprite->posY = iterator.second->posY;
							carObjectSprite->ID = iterator.second->ID;
							this->listOfObjectSprites.push_front(carObjectSprite);
						}
					}
				}
			}
		}
		else
		{
			std::smatch wynik; // tutaj bêdzie zapisany wynik
			if (std::regex_search(iterator.first, wynik, wzorzec))
			{
				if (wynik[0] == "frog")
				{
					ObjectSprite* frogObjectSprite = new FrogObjectSprite();
					frogObjectSprite->posX = iterator.second->posX;
					frogObjectSprite->posY = iterator.second->posY;
					frogObjectSprite->ID = iterator.second->ID;
					this->listOfObjectSprites.push_front(frogObjectSprite);
				}
				else if (wynik[0] == "car")
				{
					ObjectSprite* carObjectSprite = new CarObjectSprite();
					carObjectSprite->posX = iterator.second->posX;
					carObjectSprite->posY = iterator.second->posY;
					carObjectSprite->ID = iterator.second->ID;
					this->listOfObjectSprites.push_front(carObjectSprite);
				}
			}
		}

		
		
	}

	for (const auto& i : this->listOfObjectSprites)
	{
		i->setPosition(i->posX, i->posY);
		window->draw(*i);
	}

	////mapowanie model na modelGraphics
	//Object* frogModel = new FrogObject();
	//frogModel = allModels.at("frog");

	////Object* carModel = new CarObject();
	////carModel = allModels.at("car");

	//ObjectSprite* frogObjectSprite = new FrogObjectSprite();
	//frogObjectSprite->posX = frogModel->posX;
	//frogObjectSprite->posY = frogModel->posY;

	//frogObjectSprite->setPosition(frogObjectSprite->posX, frogObjectSprite->posY);

	////ObjectSprite* carObjectSprite = new CarObjectSprite();
	////carObjectSprite->posX = carModel->posX;
	////carObjectSprite->posY = carModel->posY;

	////carObjectSprite->setPosition(carObjectSprite->posX, carObjectSprite->posY);

	//window->draw(*frogObjectSprite);
	////window->draw(*carObjectSprite);
}